#include <bits/stdc++.h>
using namespace std;
  
int  kthcharsubstr(string s,int k){
    int left=0,res=0;
    unordered_map<char,int>m;
    for(int right=0;right<s.size();right++){
        m[s[right]]++;
     while(m.size()>k){
        m[s[left]]--;
        if(m[s[left]]==0)m.erase(s[left]);
        left++;
    }
    res+=(right-left+1);
} return res;
}
int countsubstr(string s,int k){
    return (kthcharsubstr(s,k)- kthcharsubstr(s,k-1));
}

int main() {
    string s="pqpqs";
    cout<<countsubstr(s,2);
    return 0;
}