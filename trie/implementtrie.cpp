#include <bits/stdc++.h>
using namespace std;
class trienode{
    public:
    trienode*arr[26];
    int prefixcount;
    int countend;
    trienode(){
        prefixcount=0; // how much node pass this idx
        countend=0; // how much node is and in this idx
        for(int i=0;i<26;i++){
            arr[i]=nullptr;
        }
    }
};
class trie{
    public:
    trienode*root=new trienode();
    void insert(string s){
        trienode*curr=root;
        for(char i:s){
            int idx=i-'a'; 
            if(curr->arr[idx]==nullptr){
                curr->arr[idx]=new trienode();
            }
            curr=curr->arr[idx];
            curr->prefixcount++;
        } curr->countend++;
    }
    bool search(string s){
        trienode*curr=root;
        for( auto i:s){
            int idx=i-'a';
            if(curr->arr[idx]==nullptr) return  false;
            curr=curr->arr[idx];
        } return curr->countend>0;
    }
    bool startwith(string s){
        trienode*curr=root;
        for( auto i:s){
            int idx=i-'a';
            if(curr->arr[idx]==nullptr) return  false;
            curr=curr->arr[idx];
        } return true;
    }
    int countwordequalto(string s){
            trienode*curr=root;
        for( auto i:s){
            int idx=i-'a';
            if(curr->arr[idx]==nullptr) return 0;
            curr=curr->arr[idx];
        }  return curr-> countend;
    }
    int countwordstaringht(string s){
            trienode*curr=root;
        for( auto i:s){
            int idx=i-'a';
            if(curr->arr[idx]==nullptr) return 0;
            curr=curr->arr[idx];
        }  return curr-> prefixcount;
    }
    void erase(string s){
         trienode*curr=root;
        for( auto i:s){
            int idx=i-'a';
            curr=curr->arr[idx];
             curr->prefixcount--;
        }  curr->countend--;
    }
};

int main() {
    trie t;
    t.insert("apple");
    t.insert("apple");
    //  cout<<t.search("apple")<<endl;
    // cout<<t.countwordequalto("apple")<<endl;
    cout<<t.countwordstaringht("app")<<endl;
     cout<<t.startwith("ap")<<endl;


    return 0;
}