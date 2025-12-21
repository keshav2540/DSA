#include <bits/stdc++.h>
using namespace std;
int helper(int i,int j,bool istrue ,string &arr){
    if(i>j) return 0;
    if(i==j) {
        if(istrue) return arr[i]=='T';
        else return arr[i]=='F';
    }
    int way=0; 
    for(int k=i+1;k<=j-1;k+=2){
    int left_t=helper(i,k-1,1,arr);
    int left_f=helper(i,k-1,0,arr);
    int right_f=helper(k+1,j,0,arr);
    int right_t=helper(k+1,j,1,arr);
    if(arr[k]=='&'){
        if(istrue) way+=left_t*right_t;
        else way+=(left_f*right_f)+(left_f*right_t)+(left_t*right_f);
    }
    else if(arr[k]=='|'){
        if(istrue)way+=(left_f*right_t)+(left_t*right_f)+left_t*right_t;
        else way+=(left_f*right_f);
    }
    else 
    {
        if(istrue)way+=(left_f*right_t)+(left_t*right_f);
        else way+=(left_f*right_f)+(left_t*right_t);
    }
    } return way;
    }
int BOOLEAN_EVALUEVATION(string &arr){
     int n=arr.size();
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    return helper(0,n-1,1,arr);
}
int main() {string arr="T^F|T&F^T|F";
 cout<<BOOLEAN_EVALUEVATION(arr);
    return 0;
}