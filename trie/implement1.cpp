#include <bits/stdc++.h>
using namespace std;
struct node
{
public:
    node *child[26];
    bool fl;
    node()
    {
       fl = false;
         for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
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
class trie
{
    node *root = new node();
    void insert(string s){
        node*curr=root;
        for(int i=0;i<s.size();i++){
           if(!curr->containkey(s[i])){
             curr->put(s[i],new node());
           }curr=curr->get(s[i]);
        } curr->setend();
    }
    bool search(string s){
        node*curr=root;
          for(int i=0;i<s.size();i++){
            if(!curr->containkey(s[i])){
                return false;
            }
            curr=curr->get(s[i]);
          } return curr->isend();
    }
    bool startwith(string prefix){
        node*curr=root;
          for(int i=0;i<prefix.size();i++){
            if(!curr->containkey(prefix[i])){
                return false;
            }
            curr=curr->get(prefix[i]);
          } return true;
    }
};

int main()
{

    return 0;
}