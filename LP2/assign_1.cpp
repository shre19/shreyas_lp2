#include <bits/stdc++.h>
using namespace std;

class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

  public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void addEdge2(int src, int dest);
  void BFS(int startVertex);
  void DFS(int vertex);
};


Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
  memset(visited, false, sizeof(vertices));
}


void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

void Graph::addEdge2(int src, int dest) {
  adjLists[src].push_front(dest);
}
// BFS algorithm
void Graph::BFS(int startVertex) {
  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout <<currVertex << "   ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::DFS(int vertex){
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];
  
  cout<<vertex<<" ";
  list<int>::iterator i;
  for(i = adjList.begin(); i!=adjList.end(); i++){
    if(!visited[*i]){
      DFS(*i);
    }
  }
}

int main() {
    cout<<"Enter total number vertices in a graph: ";
    int vertices;
    cin>>vertices;
    Graph g(vertices);
    int n=0;
    do
    {
        cout<<"Enter 1.to add an edge    2.to start traversel     -1.exit\n";
        cin>>n;
        if(n==1){
            int a, b;
            cout<<"Enter source vetex and destination vertex: ";
            cin>>a>>b;
            g.addEdge(a, b);
        }
        else if(n==2){
            int choice;
            cout<<"1.BFS   2.DFS   -1.Exit  ";
            cin>>choice;
            cout<<"Enter first vertex: ";
            int x;
            cin>>x;
            if(choice == 1){
              g.BFS(x);
            }
            else if(choice == 2){
              g.DFS(x);
            }
            break;
        }
    } while (n!=-1);
    
    return 0;
}