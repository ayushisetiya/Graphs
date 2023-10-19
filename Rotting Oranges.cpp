class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int n=grid.size(),m=grid[0].size();
     
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
          int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                if(grid[i][j]==1)
                fresh++;
            }
        }
        int afterfresh=0,tm=0;
while(!q.empty())
{
    int row=q.front().first.first;
    int col=q.front().first.second;
    int t=q.front().second;
    tm=max(tm,t);
    q.pop();
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1&&!visited[nrow][ncol])
        {
            q.push({{nrow,ncol},t+1});
            visited[nrow][ncol]=2;
            afterfresh++;
        }
    }
}
if(fresh!=afterfresh)
return -1;
return tm;
    }
};
