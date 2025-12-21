#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node*left;
    node*right;
    node(int a){
        val=a;
        left=nullptr;
        right=nullptr;
    }
};
vector<int>postorder(node*root){
    vector<int>ans;
    stack<node*>st1;
    node*curr=root;
    while(curr!=nullptr || !st1.empty()){
        if(curr!=nullptr){
            st1.push(curr);
            curr=curr->left;
        }
        else {
             node*temp=st1.top()->right;
            if(temp==nullptr){
                temp=st1.top();
                st1.pop();
                ans.push_back(temp->val);
                while(!st1.empty()&& temp==st1.top()->right){
                    temp=st1.top();
                    st1.pop();
                    ans.push_back(temp->val);
                }
            }
            else{
                curr=temp;
            } 
        }
    } return ans;
}

int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    for (auto i:postorder(root))cout<<i<<" ";
    return 0;
}