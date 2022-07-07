#include<bits/stdc++.h>

using namespace std;

//Approach 1
/*
bool isSafe(int col, int row, vector<string> &board, int n){
    int rw = row;
    int cl = col;
    while(col >= 0 && row >= 0){
        if(board[col][row] == 'Q') return false;
        col--;
        row--;
    }

    row = rw;
    col = cl;
    while(col >= 0){
        if(board[col][row] == 'Q') return false;
        col--;
    }

    row = rw;
    col = cl;
    while(col >= 0 && row < n){
        if(board[col][row] == 'Q') return false;
        col--;
        row++;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(col,row,board,n)){
            board[col][row] = 'Q';
            solve(col+1,board,ans,n);
            board[col][row] = '*';
        }
    }
}

int main(){
    int n = 4;
    vector<string> board(n);
    vector<vector<string>> ans;
    string s(n,'*');

    for(int i=0;i<n;i++){
        board[i] = s;
    }

    solve(0,board,ans,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
}
*/

//Approach 2

void solve(int col, vector<string> &board, vector<int> &leftrow, vector<int> &lowerDiag, vector<int> &upperDiag, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[(n-1) + col - row] == 0){
            board[col][row] = 'Q';
            leftrow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[(n-1) + col - row] = 1;
            solve(col+1,board,leftrow,lowerDiag,upperDiag,ans,n);
            board[col][row] = '*';
            leftrow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[(n-1) + col - row] = 0;
        }
    }
}

int main(){
    int n = 4;
    vector<string> board(n);
    vector<vector<string>> ans;
    vector<int> leftrow(n,0), lowerDiag(2*n-1,0), upperDiag(2*n-1,0);
    string s(n,'*');
    

    for(int i=0;i<n;i++){
        board[i] = s;
    }

    solve(0,board,leftrow,lowerDiag,upperDiag,ans,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}