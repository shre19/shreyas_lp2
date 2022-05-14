#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans, int node){
    vis[node] = true;
    ans.push_back(node);
    for(auto& it: adj[node]){
        if(!vis[it]){
            dfs(adj, vis, ans, it);
        }
    }
}

void bfs(vector<vector<int>>& adj, int start){
    int n = adj.size();
    vector<int> ans;
    vector<bool> vis(n, false);
    queue<int> q;
    vis[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = true;
                q.push(it);
            }
        }
    }
    for(int i: ans){
        cout<<i<<" ";
    } 
}

int main(){
    int n, m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int start, end;
        cout<<"Enter strting and ending node of an edge: ";
        cin>>start>>end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    while(1){
        int opt;
        cout<<"Enter 1 : BFS Search     2 : DFS Search      -1: Exit   : ";
        cin>>opt;
        if(opt == 1){
            bfs(adj, 0);
        }
        else if(opt == 2){
            vector<bool> vis(n, false);
            vector<int> ans;
            dfs(adj, vis,ans, 0);
            for(int i: ans){
                cout<<i<<" ";
            }
        }
        else{
            break;
        }
        cout<<endl;
    }
    return 0;

}