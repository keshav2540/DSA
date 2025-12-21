#include <bits/stdc++.h>
using namespace std;
long long int pow(int x,int y){
    if(y==0) return 1;
    if(y==1) return x;
    if(y&1==0) return pow(x*x,y/2);
    else return x*pow(x,y-1);
}
long long goodnumber(int n)
{ long int a=1e9+7;
 return( (pow(5,(n+1)/2)*pow(4,n/2))%a);
}

int main()
{    
    cout << (goodnumber(29));

    return 0;
}