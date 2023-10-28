#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
   bool detect_cycle_dfs(int node,int visited[],int path_visited[],vector<int>adj[]){
      visited[node]=1;
      path_visited[node]=1;
      
      for(auto it:adj[node]){
          if(!visited[it]){
              if(detect_cycle_dfs(it,visited,path_visited,adj)){
                  return true;
              }
          }
          else if(path_visited[it]){
              return true;
          }
          
      }
      path_visited[node]=0;
      return false;
        
    
  } 
  public:
    
        bool isCyclic(int V, vector<int> adj[]) {
        int visited[V]={0};
        int path_visited[V]={0};
        
        for(int i=0;i<V;i++){
            if(detect_cycle_dfs(i,visited,path_visited,adj)==true){
                return true;
            }
        }
        return false;
    }
};