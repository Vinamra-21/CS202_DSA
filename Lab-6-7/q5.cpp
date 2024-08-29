#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>>& adjList,int startNode, vector<bool>& visited){
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();
        cout<<currentNode<<" ";
        for(int neighbour: adjList[currentNode]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}
void addEdge(vector<vector<int>>& adjList, int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main(){
    int vertices = 5;
    vector<vector<int>> adjList(vertices);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2); 
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    vector<bool> visited(vertices, false);
    cout<<"BFS traversal starting from vertex 0: ";
    bfs(adjList, 1, visited);
    return 0;
}