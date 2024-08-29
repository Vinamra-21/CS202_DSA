#include<iostream>
#include<vector>

using namespace std;

class Graph{
    private:
        int V;
        vector<vector<int>> adjMatrix;
        vector<vector<int>> adjList;

    public:
        Graph(int vertices ){
            V=vertices;
            adjMatrix.resize(V,vector<int>(V,0));
            adjList.resize(V);
        }

        void addEdge(int src ,int dest, bool isdirected=true){
            adjMatrix[src][dest]=1;
            adjList[src].push_back(dest);
            if(!isdirected){
                adjMatrix[dest][src];
                adjList[dest].push_back(src);
            }
        }

        void printMatrix(){
            cout<<"Ajacency matrix:-"<<endl;
            for(int i=0;i<V;++i){
                for(int j=0;j<V;++j){
                    cout<<adjMatrix[i][j]<<" ";
                }
                cout<<endl;
            }

        }
        void printList(){
            cout<<"AdjacencyList:-"<<endl;
            for(int i=0;i<V;++i){
                cout<<i<<"->";
                for(int j:adjList[i]){
                    cout<<j<<" ";
                }
                cout<<endl;
            }

        }
        void computeDegree(){
            vector<int> inDegree(V,0);
            vector<int> outDegree(V,0);

            for(int i=0;i<V;++i){
                for(int j=0;j<V;++j){
                    if(adjMatrix[i][j]==1){
                        ++outDegree[i];
                        ++inDegree[j];
                    }
                }
            }
            cout<<"Node\tInDegree\tOutDegree"<<endl;
            for(int i=0;i<V;++i){
                cout<<i<<"\t"<<inDegree[i]<<"\t"<<outDegree[i]<<endl;
            }

        }

};
int main(){
    Graph directed_map(6);
    directed_map.addEdge(0,1);
    directed_map.addEdge(1,2);
    directed_map.addEdge(2,5);
    directed_map.addEdge(5,3);
    directed_map.addEdge(3,4);
    directed_map.addEdge(1,3);
    directed_map.addEdge(0,4);

    directed_map.printList();
    directed_map.printMatrix();
    directed_map.computeDegree();


    cout<<endl;

    Graph undirected_map(6);
    undirected_map.addEdge(0,1,false);
    undirected_map.addEdge(1,2,false);
    undirected_map.addEdge(2,5,false);
    undirected_map.addEdge(5,3,false);
    undirected_map.addEdge(3,4,false);
    undirected_map.addEdge(1,3,false);
    undirected_map.addEdge(0,4,false);
    
    undirected_map.printList();
    undirected_map.printMatrix();
    undirected_map.computeDegree();
    return 0;
}