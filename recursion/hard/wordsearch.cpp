#include <bits/stdc++.h>
using namespace std;
bool helper(vector<vector<char>>&wordmat,string word,int row,int col, int idx){
    if(idx==word.size()){
         return true;
    }
    if(row<0 ||col<0||row>=wordmat.size()||col>=wordmat[0].size()||wordmat[row][col]!=word[idx]) return false;
    char temp=wordmat[row][col];
    wordmat[row][col]='#';
     bool found=helper(wordmat,word,row+1,col,idx+1)||helper(wordmat,word,row-1,col,idx+1)||helper(wordmat,word,row,col-1,idx+1)||helper(wordmat,word,row,col+1,idx+1);
     wordmat[row][col]=temp;
     return found;
}

bool exist(vector<vector<char>>&wordmat,string word){
    for(int i=0;i<wordmat.size();i++)
   { for(int j=0;j<wordmat[i].size();j++){
    if(wordmat[i][j]==word[0]){
         if(helper(wordmat,word,i,j,0)) return true;
    }
   }} return false;
}

int main() {
    vector<vector<char>>mat={{'A','B','C','E'},
                             {'S','F','C','S'},
                             {'A','D','E','F'}};
string s="SABFCCESFEDREW";
cout<<exist(mat,s);

    return 0;
}