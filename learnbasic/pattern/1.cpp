#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {int n;
    cout<<"enter a number"<<endl;
    // cin>> n;
    n=5;
    for(int i=1;i<=(2*n-1);i++) 
    { for(int j=0;j<=(i-1);j++)cout<<" ";
        for(int k=1;k<=(2*n-(2*i-1));k++){
        cout<<"*";
    } cout<<endl;}

    
    return 0;
}