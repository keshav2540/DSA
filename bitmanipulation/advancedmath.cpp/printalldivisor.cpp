#include <bits/stdc++.h>
using namespace std;
void print(int n)
{
    for (int i = 1; i <= n; i++)if (n % i == 0) cout << i<<" ";
    }
void print2(int n){
 for( int i=1;i*i<=n;i++)if (n % i == 0)cout << i<<" "<<n/i<<" ";
 }


int main()
{
    print2(32);
     return 0;
}