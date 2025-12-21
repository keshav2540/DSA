#include <bits/stdc++.h>
using namespace std;
bool issafe(int row,int col,vector<string>board,int n){
    int prirow=row;
    int pricol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }
    row=prirow;
    col=pricol;
    while(col>=0){
       if(board[row][col]=='Q') return false;
       col--;  
    }
     row=prirow;
    col=pricol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
    } 
    return true;
}
void placequeen(int col,int n,vector<string>&board,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,board,n)){
            board[row][col]='Q';
            placequeen(col+1,n,board,ans);
            board[row][col]='.';
        }
    }
}

int main() {
    int n=4;
    vector<string>board(n);
    vector<vector<string>>ans;
    string s(n,'.');
    for(auto &i:board) i=s;
    placequeen(0,n,board ,ans);
    for(auto &i:ans) {for(auto j:i) cout<<j<<endl; cout<<endl;}
    return 0;
}