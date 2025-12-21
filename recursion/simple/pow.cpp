#include <bits/stdc++.h>
using namespace std;
int pow(int x,int y){
    if(y==0) return 1;
    if(y==1) return x;
    if(y&1==0) return pow(x*x,y/2);
    else return x*pow(x,y-1);
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b);

    return 0;
}