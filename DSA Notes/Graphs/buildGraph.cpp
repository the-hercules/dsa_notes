// degree of a node is how many edges attached to it(for undirected graph)
//  total degree of graph is twice the number of edges(edges is the line between 2 node)
// indegree of a graph is how many edges are coming into a node(for directed graphs)
// outdegree of a graph is how many edges are going out of a node(for directed graphs)
// edge weight is the weight of the line between 2 nodes

#include <bits/stdc++.h>
using namespace std;

// graph can be stored in 1. adjacency matrix 2. adjacency list
// adjacency matrix is a 2d array of size v*v where v is the number of vertices
// adjacency list is a array of linked list where each element is a linked list of all the nodes connected to it
// adjacency matrix can be very costly as it takes O(v^2) space
// adjacency list is more efficient as it takes O(v+e) space where e is the number of edges
template <typename T>
class graph {
   public:
    unordered_map<T, list<T>> adj;
    void addEdge(T u, T v, bool direction) {
        // 0 undirected
        // 1 directed
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }
    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};
int main() {
    int nodes;
    cout << "Enter number of nodes ";
    cin >> nodes;
    int edges;
    cout << "Enter number of edges";
    cin >> edges;
    graph<int> g;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printAdjList();
}