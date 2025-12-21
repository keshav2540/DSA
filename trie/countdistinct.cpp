#include <bits/stdc++.h>
using namespace std;
struct node
{
public:
    node *child[26]={nullptr};
    bool fl;
    node()
    {
        fl = false;
        // for(int i=0;i<26;i++){
        //     child[i]=nullptr;
        // }
    }
    bool containkey(char key)
    {
        return (child[key - 'a'] != nullptr);
    }
    void put(char ch,node*node){
        child[ch-'a']=node;
    }
    node*get(char ch)
    {
        return child[ch - 'a'];
    }
    void setend(){
        fl=true;
    }
    bool isend(){
        return fl;
    }
};
int countdistinet(string &s){
    int count=0;
    node*root=new node();
    for(int i=0;i<s.size();i++){
        node*temp=root;
       for(int j=i;j<s.size();j++){
        if(temp->child[s[j]-'a']==nullptr){
            count++;
            temp->put(s[j],new node());
        }
       temp= temp->get(s[j]);
       } 
    } return count+ 1; // empty node;
}

int main() {
    string s="aba";
    cout<<countdistinet(s);
    return 0;
}