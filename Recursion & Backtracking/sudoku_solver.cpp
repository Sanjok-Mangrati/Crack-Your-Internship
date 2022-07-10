/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

One valid solution will suffice.
*/

#include<bits/stdc++.h>

using namespace std;

bool isValid(char c, int row, int col, vector<vector<char>> &board);

bool solve(vector<vector<char>> &board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){

            if(board[i][j] == '.'){

                for(char c = '1';c <= '9';c++){

                    if(isValid(c,i,j,board)){
                        board[i][j] = c;

                        if(solve(board) == true)
                            return true;
                        else{
                            board[i][j] = '.';
                        }
                    }
                }

            return false;
            
            }
        }
    }

    return true;
}

bool isValid(char c, int row, int col, vector<vector<char>> &board){
    for(int i=0;i<9;i++){
        if(board[i][col] == c)    //Checking for rows
            return false;
        if(board[row][i] == c)    //Checking for coloumns
            return false;
        if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c)     //Checking for submatrix 3x3
            return false;
    }
    return true;
}


int main(){
    vector<vector<char>> board   {  {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};

    solve(board);

    cout << endl <<  "Solution:" <<  endl;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}