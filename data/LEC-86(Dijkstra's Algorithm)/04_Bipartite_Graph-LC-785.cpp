#include<bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<int> color, vector<vector<int>>& graph){
    int n = graph.size();
    queue<int> q;

    q.push(src);
    color[src] = src; // set-A

    while(not q.empty()){
        int curr = q.front();
        q.pop();

        for(auto& neighbour: graph[curr]){
            if(color[neighbour] == -1){
                color[neighbour] = !color[curr];
                q.push(neighbour);
            }
            else if(color[curr] == color[neighbour]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            if(!bfs(i, color, graph)){
                return false;
            }
        }
    }

    return true;
}

int main(){
    // int n, m;
    // cin>>n>>m;

    vector<vector<int>> graph;
    // for(int i=0; i<m; i++){
    //     int u, v;
    //     cin>>u>>v;
    //     graph[u].push_back(v);
    //     graph[v].push_back(u);
    // }

    // graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    graph = {{1,3},{0,2},{1,3},{0,2}};

    if(isBipartite(graph)){
        cout<<"Yes Bipartite Graph"<<endl;
    }
    else{
        cout<<"Not a Bipartite Graph"<<endl;
    }

    return 0;
}