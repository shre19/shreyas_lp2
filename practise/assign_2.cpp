#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> goal(3, vector<int>(3));
vector<vector<int>> a(3, vector<int>(3));
map<vector<vector<int>>,  vector<vector<int>> > parent;
map<vector<vector<int>>, bool> vis;

bool isGoal(vector<vector<int>> v){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(goal[i][j] != v[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int i, int j){
    if(i>=0 && i<3 && j>=0 && j<3){
        return true;
    }
    return false;
}

void printPath(vector<vector<int>> v){
    if(parent.count(v)){
        printPath(parent[v]);
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<endl;
}

int manhatten(vector<vector<int>> t, int moves){
    int dist = moves;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(t[i][j] != 0){
                for(int x=0; x<3; x++){
                    for(int y=0; y<3; y++){
                        if(t[i][j] == goal[i][j]){
                            dist += abs(i-x)+abs(j-y);
                        }
                    }
                }
            }
        }
    }
    return dist;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<vector<int>>> neighbours(vector<vector<int>> v){
    vector<vector<vector<int>>> ans;
    int cx, cy;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(v[i][j] == 0){
                cx = i;
                cy = j;
                break;
            }
        }
    }
    for(int i=0; i<4; i++){
        vector<vector<int>> temp = v;
        if(isSafe(cx+dx[i], cy+dy[i])){
            swap(temp[cx+dx[i]][cy+dy[i]], temp[cx][cy]);
            ans.push_back(temp);
        }
    }
    return ans;
}

typedef pair<vector<vector<int>>, int> state;

struct cmp {
    bool operator() (state a, state b){
        int am = manhatten(a.first, a.second);
        int bm = manhatten(b.first, b.second);
        return am<bm;
    }
};

int main(){

    goal[0][0] = 1;
    goal[0][1] = 2;
    goal[0][2] = 3;
    goal[1][0] = 4;
    goal[1][1] = 5;
    goal[1][2] = 6;
    goal[2][0] = 7;
    goal[2][1] = 8;
    goal[2][2] = 0;

    cout<<"Enter initial State: \n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
        }
    }

    priority_queue<state, vector<state>, cmp> pq;
    pq.push(state(a, 0)); 
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        vector<vector<int>> curr = it.first;
        vis[curr] = true;
        if(isGoal(curr)){
            
            printPath(curr);
            break;
        }

        int moves = it.second;
        int dist = moves;
        auto ns = neighbours(curr);
        for(auto st : ns){

            if(!vis[st]){
                vis[st] = true;
                pq.push(state(st, moves+1));
                //parent.insert(pair<vector<vector<int> > , vector<vector<int> > >(st,curr));
                parent.insert({st, curr});
            }
        }
    }   

    return 0;
}

// 1 2 3 
// 4 6 5 
// 8 7 0 