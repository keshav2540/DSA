#include <bits/stdc++.h>
using namespace std;
 void helper(stack<int>&st,int  element){
    if(st.empty()){ st.push(element);return ;}
    int a=st.top();
    if(st.top()<element){ 
        st.pop();
        helper(st,element);
        st.push(a);}
    else{
        st.push(element);
    }
    return ;
}
void sortstack(stack<int>&st){
    if(st.empty())return;
    int a=st.top();
    st.pop();
    sortstack(st);
    helper(st,a);
}
int main() {
    stack<int>st;
    st.push(1);
    st.push(4);
    st.push(6);
    st.push(5);
    st.push(3);
    st.push(78);
    st.push(100);
    st.push(2);
    sortstack(st);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    return 0;
}