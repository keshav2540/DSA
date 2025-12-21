#include <bits/stdc++.h>
using namespace std;
// i read two type
// one is this;
// second in power set problen
int main() {
    int a=7;
    int b=12;
    int pick=(b<<13)|a;
    int b2=pick>>13;
    int a2=pick&((1<<13)-1);
    cout<<pick<<endl;
    cout<<a2<<endl;
    cout<<b2<<endl;
    return 0;
}