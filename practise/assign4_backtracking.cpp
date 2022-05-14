#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<string>& board, int row, int col, int n){
    int r = row;
    int c = col;

    c--;
    while(c>=0){
        if(board[r][c] == 'Q'){
            return false;
        }
        c--;
    }
    c = col;

    c--;
    r--;
    while(r>=0 && c>=0){
        if(board[r][c] == 'Q'){
            return false;
        }
        r--;
        c--;
    }

    r = row;
    c = col;
    
    r++;
    c--;
    while(c>=0 && r<n){
        if(board[r][c] == 'Q'){
            return false;
        }
        r++;
        c--;
    }
    return true;
}

void solve(vector<vector<string>>& ans, vector<string>& board, int col, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++){
        if(isSafe(board, row ,col, n)){
            board[row][col] = 'Q';
            solve(ans, board, col+1, n);
        }
        board[row][col] = '.';
    }
}

int main(){
    int n;
    cout<<"Enter number of rows or columns: "; cin>>n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    solve(ans, board, 0, n);
    cout<<"Number of possible boards are "<<ans.size()<<'\n';
    for(auto& b: ans){
        for(auto& el: b){
            for(auto& ch: el){
                cout<<ch<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}