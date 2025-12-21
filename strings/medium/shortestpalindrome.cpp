#include <bits/stdc++.h>
using namespace std;
vector<int>lps(string s){
vector<int>lps(s.size());
 lps[0]=0;//always
 int n=s.size();
 int len=0,i=1;
    while(i<n){
        if(s[i]==s[len])   
          { len++;
        lps[i]=len;
           i++;}
        else{
            if(len!=0){//srink prefix; 
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }return lps;
}
string shortestpalindrome(string s){
    string r=s;
    reverse(r.begin(),r.end());
    string temp=s+'#'+r;
    int n=temp.size();
    vector<int>lpsarr=lps(temp);
    int lastlps=lpsarr[lpsarr.size()-1];
    return (r.substr(0,s.size()-lastlps)+s);
}

int main() {
  cout<<shortestpalindrome("abcd");
    return 0;
}