//Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group
// of connected 1s (horizontally or vertically) forms an island. Two islands are considered
//to be distinct if and only if one island is not equal
//to another (not rotated or reflected).
#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
  void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,
 vector<pair<int,int>>&vec,int row_,int col_,int m,int n){
       vis[row][col]=1;
       //IMPORTANT
       //to store the position/shape of the 1's in grid we are storing the relative position of elements and pushing it in set
       vec.push_back({row-row_,col-col_});
       for(int i=-1;i<=1;i++){
           for(int j=-1;j<=1;j++){
               if(i==0&&j!=0||i!=0&&j==0){
                   int nrow=row+i;
                   int ncol=col+j;
               
               if(nrow<m&&nrow>=0&&ncol<n&&ncol>=0&&!vis[nrow][ncol]
               &&grid[nrow][ncol]==1){
                  
                  
                   dfs(nrow,ncol,vis,grid,vec,row_,col_,m,n);
               }}
           }
       }
      
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //using unordered_set gives error because it does not work well with custom data structure;
       set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&!vis[i][j]){
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,grid,vec,i,j,m,n);
                    st.insert(vec);
                }
            }
        }
     return st.size();
    }
};
