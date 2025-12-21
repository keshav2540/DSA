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
  int height(node *root){
        if(root==nullptr) return 0;
        int height1=height(root->left);
        int height2=height(root->right);
        return 1+max(height1,height2);} 

bool checkbalanced(node*root){
    if(root==NULL) return true;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1) return false;
    bool left=checkbalanced(root->left);
    bool right=checkbalanced(root->right);
    if(!left||!right) return false;
    return true;
}
int checkbalanced2(node*root){
    if(root==NULL) return 0;
    int lh=checkbalanced2(root->left);
    int rh=checkbalanced2(root->right);
    if(abs(lh-rh)>1) return -1;
    if(lh==-1||rh==-1) return -1;  
     return max(lh,rh)+1;
}

int main() {
    node*root=new node(1);
    // root->left=new node(2);
    root->right=new node(3);
    // root->left->left=new node(4);
    // root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<checkbalanced2(root);//it return height if balanced else retuern -1;
    return 0;
}