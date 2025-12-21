#include <bits/stdc++.h>
using namespace std;
int wordladderlength(string startnode,string targetnode,vector<string>wordlist){
 queue<pair<string,int>>q;
 q.push({startnode,1});
 unordered_set<string>st(wordlist.begin(),wordlist.end());
 st.erase(startnode);
 while(!q.empty()){
    string word=q.front().first;
    int step=q.front().second;
    q.pop();
    if(word==targetnode) return step;
    for(int i=0;i<word.size();i++){
        char original=word[i];
        for(char ch='a';ch<='z';ch++){
        word[i]=ch;
        if(st.find(word)!=st.end()){
           st.erase(word);
           q.push({word,step+1});
        }}
    word[i]=original;
 }
} return 0;}
int main() {vector<string>wordlist={"hot","dot","dog","lot","log","cog"};
string startnode="hit";
string target="cog";
cout<<wordladderlength(startnode,target,wordlist);
    return 0;
}