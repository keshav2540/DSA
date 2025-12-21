#include <bits/stdc++.h>
using namespace std;
int requirevalidparathsis(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
      if(s[i]=='('){
        st.push(s[i]);
      }
      if(s[i]==')'){
        if(!st.empty()&&st.top()=='('){
            st.pop();
        }
        else st.push(s[i]);
      }
    } return st.size();
}

int main() {
 string s="(()))";
 cout<<requirevalidparathsis(s);
    return 0;
}