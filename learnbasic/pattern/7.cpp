#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
    int n=4;
    for(int i=0;i<=(2*n-2);i++){
        for(int j=0;j<=(2*n-2);j++)
        { int left=i;
          int right=j;
          int uper=(2*n-2)-i;
          int bottum= (2*n-2)-j;
          int h=min(min(left,right),min(uper,bottum));
          cout<<4-h<<" ";
        }
 cout<<endl; }
    return 0;
}