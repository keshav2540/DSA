#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() { int n,j,k;
    cin>>n;
        for(int i=0;i<n;i++){
        for( j=n-i;j>0;j--){
           cout<<"* ";
        }
        for(k=n-i;k<=n-1;k++){
           cout<<"  ";
        }
        for(k=n-i;k<=n-1;k++){
           cout<<"  ";
        }
         for( j=n-i;j>0;j--){
           cout<<"* ";
        }
  cout<<endl;  }
    for(int i=0;i<n;i++){
        for( j=i;j>=0;j--){
           cout<<"* ";
        }
        for(k=n-i;k>1;k--){
           cout<<"  ";
        }
         for(k=n-i;k>1;k--){
           cout<<"  ";
        }
         for( j=i;j>=0;j--){
           cout<<"* ";
        }
        cout<<endl;}
    return 0;
}