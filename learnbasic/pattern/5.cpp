#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {int n=5;  
     char a='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i+1);j++){
            cout<<a;
        } cout<<endl;
        a++;
    }
    return 0;
}