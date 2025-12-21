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
string serialize(node *root)
{
    if (!root)
        return "";
    string s = "";
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        if (curr == nullptr)
        {
            s.append("#,");
        }
        else
            s.append(to_string(curr->val) + ',');
        if (curr != nullptr)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}
node *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    node *root = new node(stoi(str));
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
        {
            temp->left = nullptr;
        }
        else
        {
            node *leftnode = new node(stoi(str));
            temp->left = leftnode;
            q.push(leftnode);
        }
        getline(s, str, ',');
        if (str == "#")
        {
            temp->right = nullptr;
        }
        else
        {
            node *rightnode = new node(stoi(str));
            temp->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;
}
int main()
{
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // // root->left->left = new node(4);
    // root->left->right = new node(5);
    // // root->right->left = new node(6);
    // root->right->right = new node(7);
    // cout << serialize(root);
       node*root=deserialize("1,2,3,#,5,#,7,#,#,#,#,");
        cout<<root->val<<endl;
        cout<<root->left->val<<endl;
        cout<<root->right->val<<endl;
        // cout<<root->left->left->val<<endl;
        cout<<root->left->right->val<<endl;
        // cout<<root->right->left->val<<endl;
        cout<<root->right->right->val<<endl;
}