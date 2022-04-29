#include<bits/stdc++.h>
using namespace std;
void bfs_rec(vector<int>vec[],vector<int> &visit, queue<int> & q)
{
    if(q.empty()) 
    {
        return ;
    }
    int ele=q.front();
    q.pop();
    cout<<ele<<" ";
    vector<int>a=vec[ele];
    for(int i=0;i<a.size();i++)
    {   
        if(!visit[a[i]])
        {
            visit[a[i]]=1;
            q.push(a[i]);
        }
    }
    bfs_rec(vec,visit,q);
}
void BFS(vector<int>vec[],int n)
{
    vector<int>visit(n+1,0);
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            q.push(i);
            bfs_rec(vec,visit,q);
        }
    }

}
void dfs_rec(vector<int>vec[],vector<int> &visit,int n)
{
     vector<int>a=vec[n];
     cout<<n<<" ";
     for(int i=0;i<a.size();i++)
     {
         int ele=a[i];
         if(visit[a[i]]==0)
         {
             visit[a[i]]=1;
             dfs_rec(vec,visit,ele);
         }
     }
}
void DFS(vector<int>vec[],int n)
{
    vector<int>visit(n+1,0);
    
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            dfs_rec(vec,visit,i);
        }
    }

}
int main()
{ 
    int n,edge,u,v;
    cout<<"Enter Number of Vertices : ";
    cin>>n;
    vector<int>vec[n+1];
    cout<<"Enter Number of Edges : ";
    cin>>edge; 
    for(int i=0;i<edge;i++)
    {
        cout<<"Enter starting index : ";
        cin>>u;
        cout<<"Enter Ending vertex : ";
        cin>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    cout<<"\nGraph\n";

    for(int i=1;i<n+1;i++)
    {
        cout<<i<<" -> ";
        vector<int>a=vec[i];
        for(int j=0;j<vec[i].size();j++)
         {
             cout<<a[j]<<" ";
         }
        cout<<"\n";
    }

    cout<<"\n\nBFS Treversal \n";
    BFS(vec,n);

    cout<<"\n\nDFS Treversal \n";
    DFS(vec,n);
    
}
