#include <bits/stdc++.h>
using namespace std;
int priority( char c){
    if(c=='^') return 3;
    if(c=='*'|| c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    else return 0;
}
string infixtopostfix(string s){
    stack<char>st;
    string ans="";
    int i=0;
    while(i<s.size()){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&&s[i]<='z')|| (s[i]>='0'&&s[i]<='9')){
            ans+=s[i];
           }
        else if(s[i]=='('){
            st.push(s[i]);
        } 
        else if(s[i]==')'){
            while(!st.empty()&& st.top()!='('){
                ans+=st.top();
                st.pop();
            } 
            if(!st.empty()&& st.top()=='(') st.pop();

        }
        else {
            while(!st.empty() && priority(s[i])<priority(st.top())){
                ans+=st.top();
                st.pop(); 
            }
            st.push(s[i]);
        }
        i++;
}
 while(!st.empty()){
    ans+=st.top();
    st.pop();
}
 return ans;}
string infixtoprefix(string &s){
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
         if(s[i]=='(') s[i]=')';
         else if(s[i]==')')s[i]='(';
    }
    string ans=infixtopostfix(s);
    reverse(ans.begin(),ans.end());
    return ans; }

int main() { string s="(a+b)*c-d+f";
    cout<<infixtoprefix(s);
    return 0;
}