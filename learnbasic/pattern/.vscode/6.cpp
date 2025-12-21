#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() { int n=5;
  
     for(int i=1;i<=n;i++){  char o='A';
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        } 
        for(int k=1;k<=(2*i-1);k++){
            cout<<o;
            if(k>=i) o--;
            else o++;
        }
   cout<<endl;}
    return 0;
}