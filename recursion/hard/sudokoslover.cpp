#include <bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<char>>&board,int row,int col,char k){
    for(int i=0;i<9;i++){
        if(board[row][i]==k) return false;
        if(board[i][col]==k) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==k) return false;
    } return true;
}
bool solve(vector<vector<char>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]=='.'){
                for(int k='1';k<='9';k++){
                    if(isvalid(board,i,j,k)){
                        board[i][j]=k;
                        if(solve(board)==true){
                            return true;
                        }
                        else board[i][j]='.';
                    }
                }  return false;
            }
           
        }   

    } return true;
}

int main() {
      vector<vector<char>>board={{'1','.','.','.','.','.','9','5','.'},
                                 {'5','.','.','.','.','.','.','.','.'},
                                 {'3','8','6','1','5','9','.','.','.'},
                                 {'8','.','3','.','2','4','.','.','.'},
                                 {'.','.','.','3','8','.','.','6','2'},
                                 {'.','2','1','.','.','.','.','.','3'},
                                 {'.','.','5','.','3','6','.','1','.'},
                                 {'2','3','.','7','.','5','.','.','9'},
                                 {'.','.','.','.','4','.','.','.','5'}
                                                                      };
 solve(board);
 for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";}
            cout<<endl;}
    return 0;
}