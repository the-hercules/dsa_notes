#include <bits/stdc++.h>
using namespace std;

// topological sorting is only valid for directed acyclic graphs;
// topological sorting is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
class Solution {
   private:
    void topologicalSortDfs(int node, int visited[], vector<int> adj[],stack<int>&st) {
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                topologicalSortDfs(it,visited,adj,st);
                }
            }
//after traversal is done we push it in stack,and stack is the topological sort.
            st.push(node);
        }
    

   public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        int visited[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortDfs(i, visited, adj,st);
            }
        }
        vector<int>answer;
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        return answer;
    }
};