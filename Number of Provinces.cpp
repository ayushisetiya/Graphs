class Solution {
    private :
    void dfs(int node,vector<int>adjlist[],vector<int> &visited)
    { visited[node]=1;
        for(auto i:adjlist[node])
        {
            if(!visited[i]){
            dfs(i,adjlist,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>adjlist[v];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j]==1&&i!=j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int>visited(v,0);
        int cnt=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(visited[i]!=1)
            {
             
                cnt++;
                dfs(i,adjlist,visited);
            }
        }
        return cnt;
    }
};
