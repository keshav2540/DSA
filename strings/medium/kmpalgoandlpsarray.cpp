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
// do substring ko compare karne ke liye cps compare kar lo
int main() {
     for(int i:lps("AAACAAAA"))cout<<i<<" ";
    return 0;
}