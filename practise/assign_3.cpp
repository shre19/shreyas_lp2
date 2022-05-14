#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter number of nodes : "; cin>>n;
    cout<<"Enter number of edges: "; cin>>m;

    vector<vector<pair<int, int>>> adj(n);
    cout<<"Enter starting and ending nodes for "<<m<<" edges: \n";
    for(int i=0; i<m; i++){
        int start ,end, weight;
        cin>>start>>end>>weight;
        adj[start].push_back({end, weight});
        adj[end].push_back({start, weight});
    }
    vector<int> key(n, 1e9);
    vector<bool> mstset(n, false);
    vector<int> parent(n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    parent[0] = -1;

    while(!pq.empty()){
        auto el = pq.top();
        pq.pop();
        int node = el.second;
        mstset[node] = true;
        for(auto it: adj[node]){
            int u = it.first;
            int w = it.second;
            if(!mstset[u] && w < key[u]){
                key[u] = w;
                parent[u] = node;
                pq.push({w, u});
            }
        }
    }

    for(int i=1; i<n; i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }

    return 0;
}