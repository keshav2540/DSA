#include <bits/stdc++.h>
using namespace std;
string postfixtoinfix(string s){
    int i=0; stack<string>st;
    while(i<s.size()){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&&s[i]<='z')|| (s[i]>='0'&&s[i]<='9')){
            st.push(s.substr(i,1));
        }
        else{
            string t1=st.top();st.pop();
            string t2=st.top();st.pop();
            st.push("("+t2+s.substr(i,1)+t1+")");
        }
        i++;
    } return st.top();
}

int main() {
    string s="ab-de+f*/";
    cout<<postfixtoinfix(s);
    return 0;
}