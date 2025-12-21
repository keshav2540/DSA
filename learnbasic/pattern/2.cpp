#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {int n=5;

    for(int i=1;i<=(2*n-1);i++){
        int k=i;
        if(i>5) {
            k=(2*n-k);
        }
        for(int j=1;j<=k;j++){
            cout<<"* ";
        }
cout<<endl;
    }
    return 0;
}