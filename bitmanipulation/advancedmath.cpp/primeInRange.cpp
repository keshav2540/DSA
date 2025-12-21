#include <bits/stdc++.h>
using namespace std;
bool checkprime(int n){
    if(n==1) return false;
    int count=0;
    for(int i=1;i*i<=n;i++) if(n%i==0) count=count+2;
    if(count==2) return true;
    else return false;
}
void bf(vector<vector<int>>matrix){
    int m=matrix.size();
    for(int i=0;i<m;i++){
        int l=matrix[i][0];
        int r=matrix[i][1];
        int count=0;
        for(int j=l;j<=r;j++){
            if(checkprime(j)) count++;
        }
    cout<<count<<endl;}
}
vector<int>getseive( int n){
   vector<int>ans(n+1,1);
    ans[0]=0; ans[1]=0;
    for(int i=2;i*i<n;i++){
        if(ans[i]==1){
            for( int j=i*i;j<=n;j+=i) ans[j]=0;
        }
    } return ans;
}
void optimal(vector<vector<int>>matrix){
    vector<int>prime=getseive(1e+6);
    int m=matrix.size();
     for(int i=0;i<m;i++){
        int l=matrix[i][0];
        int r=matrix[i][1];
        int count=0;
        for(int j=l;j<=r;j++){
            if(prime[j]==1) count++;
        }
    cout<<count<<endl;   
}}

void moreoptimal(vector<vector<int>>matrix){
       vector<int>prime=getseive(1e+6);
     int count=0;
       for(int i=0;i<prime.size();i++){
        count=count+prime[i];
     prime[i]=count;
    }
    int m=matrix.size();
     for(int i=0;i<m;i++){
        int l=matrix[i][0];
        int r=matrix[i][1];
    cout<<(prime[r]-prime[l-1])<<endl;   
}}

int main() {
    vector<vector<int>>matrix={{3,10},{8,20},{1,5}};
    moreoptimal(matrix);
    return 0;
}