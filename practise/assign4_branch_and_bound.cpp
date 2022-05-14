#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<string>>& ans, vector<string>& board, vector<bool> cols, vector<bool> ndig, vector<bool> rdig, int row){
    int n = board.size();
    if(row == n){
        ans.push_back(board);
        return;
    }
    for(int col=0; col<n; col++){
        if(!cols[col] && !ndig[row+col] && !rdig[row-col+n-1]){
            board[row][col] = 'Q';
            cols[col] = true;
            ndig[row+col] = true;
            rdig[row-col+n-1] = true;

            solve(ans, board, cols, ndig, rdig, row+1);

            board[row][col] = '.';
            cols[col] = false;
            ndig[row+col] = false;
            rdig[row-col+n-1] = false;
        }
    }
}

int main(){

    int n;
    cout<<"Enter number of rows or columns: "; cin>>n;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    int t = 2*n - 1;
    
    vector<bool> cols(n, false);
    vector<bool> ndig(t, false);
    vector<bool> rdig(t, false);

    solve(ans, board, cols, ndig, rdig, 0);

    for(auto i: ans){
        for(auto j: i){
            for(auto k: j){
                cout<<k<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
    }

    return 0;
}