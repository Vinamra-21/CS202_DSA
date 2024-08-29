#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

void add_Edge(unordered_map<int, vector<int>>& graph,int u, int v){
    graph[u].push_back(v);
}

void dfs(unordered_map<int, vector<int>>& graph, int v, vector<bool>& visited, stack<int>& stack){
    visited[v] = true;
    for(int i: graph[v]){
        if(!visited[i]){
            dfs(graph, i, visited, stack);
        }
    }
    stack.push(v);
}
unordered_map<int, vector<int>> transpose(unordered_map<int, vector<int>>& graph){
    unordered_map<int, vector<int>> transposed_graph;
    for(auto& pair: graph){
        int u = pair.first;
        for(int v: pair.second){
            transposed_graph[v].push_back(u);
        }
    }
    return transposed_graph;
}

void dfs_util(unordered_map<int, vector<int>>& graph, int v, vector<bool>& visited){
    visited[v] = true;
    cout<<v<<" ";
    for(int i: graph[v]){
        if(!visited[i]){
            dfs_util(graph, i, visited);
        }
    }
}

void print_scc(unordered_map<int, vector<int>>& graph, int vertices){
    stack<int> stack;
    vector<bool> visited(vertices, false);
    for(int i=0; i<vertices; i++){
        if(!visited[i]){
            dfs(graph, i, visited, stack);
        }
    }
    unordered_map<int, vector<int>> transposed_graph = transpose(graph);
    fill(visited.begin(), visited.end(), false);
    while(!stack.empty()){
        int v = stack.top();
        stack.pop();
        if(!visited[v]){
            dfs_util(transposed_graph, v, visited);
            cout<<endl;
        }
    }
}
int main(){
    unordered_map<int, vector<int>> graph;
    add_Edge(graph, 1,0);
    add_Edge(graph, 0,2);
    add_Edge(graph, 2,1);
    add_Edge(graph, 0,3);
    add_Edge(graph, 3,4);

    cout<<"strongly connected components are: "<<endl;
    print_scc(graph,5);
    return 0;
}

