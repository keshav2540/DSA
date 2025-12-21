#include <bits/stdc++.h>
using namespace std;
const int d=256;
const int mod=101;
//using hasing in old stylecond
int rhash(string s){int p=0;
    for(int i=0;i<s.size();i++){
       p=(p*d+s[i])%mod; 
    } return p;
}
vector<int>rabinkrap(string text,string pattern){
    vector<int>ans;
    int m=text.size();
    int n=pattern.size();
    int i,j;
    int p=0;//pattern hash
    int t=0;// text hash;
    int h=1;
    for(int i=0;i<n-1;i++){
       h=(h*d)%mod;//h=256^3;
    }
     for(int i=0;i<n;i++){
       p=(p*d+pattern[i])%mod; 
       t=(t*d+text[i])%mod; 
    } 
    for(int i=0;i<=m-n;i++){
         if(p==t){
            bool match=true;
            for(int j=0;j<n;j++){
             if(pattern[j]!=text[i+j]) {match=false;
             break;}
            }
            if(match)ans.push_back(i);
         }
         if(i<m-n){
            t=((d*(t-text[i]*h))+text[i+n])%mod;
         }
         if(t<0)t=t+mod;
    }
 return ans;
}

int main() {
    string s="abc";
    string l="aaabcdmabckaabc";
    for(auto i:rabinkrap(l,s))cout<<i<<" ";

    return 0;
}