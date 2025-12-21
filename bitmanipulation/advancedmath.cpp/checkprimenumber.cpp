#include <bits/stdc++.h>
using namespace std;
void checkprime(int n){int count=0;
    for(int i=1;i*i<=n;i++) if(n%i==0) count=count+2;
    if(count==2) cout<<"its is prime number";
    else cout<<"its is not a prime number";
}

int main() {
    checkprime(5);
        return 0;
}