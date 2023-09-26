//bipartite graph is a graph which you can colour all adjacent nodes with 2 colours and no 2 adjacent nodes have same colour
//linear graph with no cycle will always be bipartite
//ANY GRAPH WITH EVEN CYCLE LENGTH CAN ALSO BE BIPARTITE
//ANY GRAPH WITH ODD CYCLE LENGTH CAN    NEVER    BE BIPARTITE


#include "bits/stdc++.h"
using namespace std;
class Solution {
private:
    bool checkBipartite(int start,vector<vector<int>>&graph,int colour[]){
        queue<int>q;
        q.push(start);
        colour[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop(); 
            for(auto it:graph[node]){
                //if node is not visited we colour it opposite to the node
                //it is connected to
                if(colour[it]==-1){
                    colour[it]=!colour[node];
                    q.push(it);
                }
                //in else condition we find that node is already visted
                //not if the colour does not match that that means the graph is not
                //bipartite
                else if(colour[it]==colour[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        int colour[V];
        //initialize visited with -1
        for(int i=0;i<V;i++){
            colour[i]=-1;
        }
        //this logic is for disconnected graph
        for(int i=0;i<V;i++){
            if(colour[i]==-1){
                if(checkBipartite(i,graph,colour)==false){
                    return false;
                }
            }
        }
        return true;
    }
};