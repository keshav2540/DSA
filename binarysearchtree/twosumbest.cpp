#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    node(int a)
    {
        val = a;
        left = nullptr;
        right = nullptr;
    }
};
class BSTITERAOTOR
{
    stack<node *> st;
    bool reverse=true;

public:
    BSTITERAOTOR(node *root,bool isreverse)
    { reverse=isreverse;
        pushall(root); 
    }
    bool hasnext()
    {
        return !st.empty();
    }
    int next()
    {
        node *temp = st.top();
        st.pop();
        if(!reverse)pushall(temp->right);
        else pushall(temp->left);
        return temp->val;
    }

private:
   void pushall(node *root)
    {
        for (; root != nullptr;)
            {    
                st.push(root);
                if(reverse==true) root=root->right;
                else root=root->left;
            }
    }
};
bool find(node*root,int sum){
    if(root==nullptr)return false;
    BSTITERAOTOR l(root,false);
    BSTITERAOTOR r(root,true);
    int i=l.next();
    int j=r.next();
    while(i<j){
        if(i+j==sum) return true;
        else if(i+j>sum) j=r.next();
        else i=l.next();
    }
   return false;
}
int main()
{
    node *root = new node(9);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->left->right = new node(3);
    root->left->left->right->right = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->left->right->right = new node(8);
    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(13);
   cout<<find(root,45);
}