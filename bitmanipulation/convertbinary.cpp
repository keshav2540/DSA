#include <bits/stdc++.h>
using namespace std;
 string convert(int n){
string s="";
if(n==0) return "0";
    while(n!=0){
        s+= char(n%2+'0');
        n=n/2;
    }
    reverse(s.begin(),s.end());
    return s;
 }
 int convertint(string s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans*=2; 
        ans+=int(s[i]-'0');
    }
     return ans;
 }
int main() {
    cout<<convertint("100");
    return 0;
}