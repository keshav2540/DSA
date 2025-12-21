#include <bits/stdc++.h> // minimum bit flip to convert to other number
using namespace std;
int convertflip(int start,int goal){
    int ans=start^goal;
    int count=0;
    // for(int i=0;i<31;i++){
    //     if(ans&(1<<i)) count++;
    // } return count ;
    while(ans!=0){
        count++;
        ans=ans&ans-1;
    } return count;}

int main() {
    cout<<convertflip(10,7);
    return 0;
}