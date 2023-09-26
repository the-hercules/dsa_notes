class Solution {
  private:
  void dfs(vector<int>adj[],int vis[],int node,vector<int>&answer){
      vis[node]=1;
      answer.push_back(node);
      for(auto it:adj[node]){
          if(!vis[it]){
              dfs(adj,vis,it,answer);
          }
      }
      
  }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        int start=0;
        vector<int>answer;
        dfs(adj,vis,start,answer);
        return answer;
    }
};