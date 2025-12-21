// its normal size question tree maximum hight ya width given node
#include <bits/stdc++.h>
using namespace std;
template <typename t>
class node
{
public:
    t val;
    node *left;
    node *right;
    node(t a)
    {
        val = a;
        left = nullptr;
        right = nullptr;
    }
};
node<int>*markparent(node<int>*root,unordered_map<node<int>*,node<int>*>&parenttrack,int target){
    queue<node<int>*>q;
    q.push(root);
    node<int>*result;
    while(!q.empty()){
        node<int>*curr=q.front();
        if(curr->val==target) result=curr;
        q.pop();
        if(curr->left){
            parenttrack[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parenttrack[curr->right]=curr;
            q.push(curr->right);
        }
    } return result;
}
int findmaxdis(unordered_map<node<int>*,node<int>*>&parenttrack,node<int>*target){
    queue<node<int>*>q;
    q.push(target);
    map<node<int>*,bool>visit;
    visit[target]=true;
    int maxi=0;
    while(!q.empty()){
        int size=q.size();
        int fl=0;
        for(int i=0;i<size;i++){
            auto nod=q.front();
            q.pop();
            if(nod->left&& !visit[nod->left]){
                fl=1;
                q.push(nod->left);
                visit[nod->left]=true;
            }
            if(nod->right&& !visit[nod->right]){
                q.push(nod->right); fl=1;
                visit[nod->right]=true;
            }
            if(parenttrack[nod]&& !visit[parenttrack[nod]]){
                q.push(parenttrack[nod]); fl=1;
                visit[parenttrack[nod]]=true;
            }
        }if(fl)maxi++;
    }
return maxi;
}
int burnit(node<int>*root,int target){
    unordered_map<node<int>*,node<int>*>parenttrack;
    node<int>*st=markparent(root,parenttrack,target);
     return findmaxdis(parenttrack,st);
}
int main()
{
    node<int> *root = new node<int>(1);
    root->left = new node<int>(2);
    root->right = new node<int>(3);
    root->left->left = new node<int>(4);
    root->left->left->left = new node<int>(8);
    root->left->right = new node<int>(5);
    root->right->left = new node<int>(6);
    root->right->right = new node<int>(7);
    root->right->right->right = new node<int>(9);
     cout<<burnit(root,9)<<" ";
}