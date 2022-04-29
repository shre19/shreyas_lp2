#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>> &board, int row, int col, int n){

    // To check if the queen is present in the current column or not
    for(int i=0;i<=col;i++){
        if(board[row][i]){
            return false;
        }
    }

    // To check the diagonal on the upper left of the current squares
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    // To check the diagonal on the upper right of the current square
    for(int i=row,j=col;j>=0 && i<n;i++,j--){
        if(board[i][j]){
            return false;
        }
    }

    // It neither of the condition is true then we can place queen at this position
    return true;

}

bool solveNQN(vector<vector<int>> &board, int column, int n){

    // Base case
    if(column>=n){
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if(isSafe(board,i,column,n)){
            board[i][column] = 1;
            if (solveNQN(board,column+1,n))
            {
                return true;
            }
            // removing the queen
            board[i][column] = 0;            
        }
    }
    
    
    return false;
    
}

void printSolution(vector<vector<int>> &board, int n){
    if(solveNQN(board,0,n)){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    else{
        cout<<"Solution is not possible"<<endl;
    }
}


int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    printSolution(board,n);
}