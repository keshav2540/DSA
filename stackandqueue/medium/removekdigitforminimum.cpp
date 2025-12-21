#include <bits/stdc++.h>
using namespace std;
string afterrmovedigit(string s,int k){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        while(!st.empty()&&st.top()>s[i]&&k>0){
            st.pop();
            k=k-1;
        }
        st.push(s[i]); }
        while(k>0){st.pop();k--;}
        if(st.empty())return 0;
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()>0&& res.back()=='0') res.pop_back();
   reverse(res.begin(),res.end());
   if(res.empty()) return "0";
   return res;
}

int main() {
string s="1432219";
int k=3;    
cout<<afterrmovedigit(s,k);
    return 0;
}