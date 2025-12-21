#include <bits/stdc++.h>
using namespace std;
int  normaldivide(int divdent,int divisor){
    int sum=0, count=0;
    while(sum+divisor<=divdent){
        count++;
        sum+=divisor;
    }
return count;
 }
 int optimaldivide(int divdent,int divisor){
    if(divdent==divisor) return 1;
    bool sign=true;
    if(divdent>=0&& divisor<0){ sign =false;
     divisor=-divisor;}
   else  if(divdent<0&& divisor>0){ sign =false;
         divdent=-divdent;}
     else{
        divisor=abs(divisor);
       divdent=abs(divdent);}
    int ans=0;
    while(divdent>=divisor){
        int count=0;
        while(divdent>=(divisor<<(count+1))) count++;
            ans+=(1<<count);
            divdent=divdent-(divisor<<(count));
       
    } return  sign?ans:-ans;
 }
int main() {
    int divdent=22;
    int divisor=-3;
    cout<<optimaldivide(divdent,divisor);
    return 0;
}