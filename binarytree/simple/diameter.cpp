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

int diameter1(node*root){int maxi=0;
    if(root==nullptr)return 0;
    int lh=height(root->left);
    int rh=height(root->left);
    maxi=max(lh+rh,maxi);
    maxi=max(diameter1(root->right),maxi);
    maxi=max(diameter1(root->left),maxi);
    return maxi;
}
 int find(node*root,int &maxi){
 if(root==nullptr)return 0;
 int lh=find(root->left,maxi);
 int rh=find(root->right,maxi);
 maxi=max(maxi,lh+rh);
 return 1+max(rh,lh);
 }
int diameter2(node*root){
    int maxi=0;
    find(root,maxi);
    return maxi;
}

int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<diameter2(root);
    
}