class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxTime=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(make_pair(i,j),0));
                    vis[i][j]=2;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> temp=q.front().first;
            int time=q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    //this condition makes it travel only in horizonal and vertial direction
                    if((i==0&&j!=0)||(i!=0&&j==0)){
                        int nrow=temp.first+i;
                        int ncol=temp.second+j;
                        if(nrow<m&&nrow>=0&&ncol<n&&ncol>=0&&vis[nrow][ncol]!=2&&grid[nrow][ncol]==1){
                        vis[nrow][ncol]=2;
                        q.push(make_pair(make_pair(nrow,ncol),time+1));
                        maxTime=max(maxTime,time+1);
                        // maxTime=time>=maxTime?time:maxTime;
                        cout<<time<<" "<<maxTime<<endl;
                        }
                    }
                }
            }
        }
        int gridMangoCount=0;
        int visMangoCount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1||grid[i][j]==2){
                    gridMangoCount++;
                }
                if(vis[i][j]==2){
                    visMangoCount++;
                }
                }
    }
    cout<<gridMangoCount<<" "<<visMangoCount<<endl;
    if(gridMangoCount!=visMangoCount){return -1;}
    else {return maxTime;}
    }   
};