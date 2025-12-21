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
void kmpsearch(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    vector<int>lpspattern=lps(pattern);
    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"pattern found at "<<i-j<<endl;
            j=lpspattern[j-1];
        }
        else if(i<n&& text[i]!=pattern[j]){
            if(j!=0) j=lpspattern[j-1];
            else i++;
        }

    }
}
int main() {
 kmpsearch("ABABABABC","ABABC");
    return 0;
}