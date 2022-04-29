#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<string>& board, int row, int col, int n){
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

void solve(vector<string>& board, vector<vector<string>>& ans, int row, int col, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0; row<n; row++){
        if(isValid(board, row, col, n)){
            board[row][col] = 'Q';
            solve(board, ans, row, col+1, n);
        }
        board[row][col] = '.';
    }
}


int main(){

    int n;
    cout<<"Enter Number of n (row and column)\n";
    cin>>n;
    vector<string> board(n, string(n, '.')); 
    vector<vector<string>> ans;
    int row = 0;    
    int col=0;
    solve(board, ans, row, col, n);
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