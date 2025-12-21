#include <bits/stdc++.h>
using namespace std;
bool ispalinderome(string s,int st,int end){
    while(st<=end){
        if(s[st++]!=s[end--]) return 0;
    } return 1;
}
void   giveplindromepartion(int ind,string s,vector<string>&path,vector<vector<string>>&ans){
    if(ind==s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(ispalinderome(s,ind,i)){
            path.push_back(s.substr(ind,i-ind+1));
             giveplindromepartion(i+1,s,path,ans);
            path.pop_back();
        }
    }
}

int main() {
    string s="aabb";
    vector<string >path;
    vector<vector<string>>ans;
    giveplindromepartion(0,s,path,ans);
    for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    } cout<<endl;
   }


    return 0;
}