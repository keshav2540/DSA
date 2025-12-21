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

public:
    BSTITERAOTOR(node *root)
    {
        pushall(root);
    }
    bool hasnext()
    {
        return st.empty() ? false : true;
    }
    int next()
    {
        node *temp = st.top();
        st.pop();
        pushall(temp->right);
        return temp->val;
    }

private:
   void pushall(node *root)
    {
        for (; root != nullptr; st.push(root), root = root->left)
            ;
    }
};
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
    BSTITERAOTOR bst(root);
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout << bst.next();//print inorder format;
    cout<<bst.hasnext();
}