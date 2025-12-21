#include <bits/stdc++.h>
using namespace std;
string helper(string s){string ans="";
    for(int i=0;i<s.size();i++){
        int count=1;
        while( i+1<s.size()&&s[i]==s[i+1]){
             count++;
             i++;
        }
        ans+=to_string(count)+s[i];
    }return ans;
}
string countsay(int n){
    string s="1";
    for(int i=1;i<n;i++){
        s=helper(s);
    }return s;
}
int main() {
    cout<<countsay(4);
    //  s=s+;
    //  cout<<char(1+'0');// if you write to string fun using this for loop in this o to 9 convet in char

    return 0;
}