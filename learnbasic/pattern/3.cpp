#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {int n=5;
    bool o=1;
    for(int i=1;i<=n;i++){ bool k=o;
        for(int j=1;j<=i;j++){
            cout<<k;
            k=!k;
        } cout<<endl;
        o=!o;
    }
    return 0;
}