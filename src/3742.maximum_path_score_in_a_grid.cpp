class Solution {
    int m, n;
    int dr[2]={0,1};
    int dc[2]={1,0};
public:
    bool isValid(int x, int y) {
        return x<m && y<n;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, 
            vector<vector<pair<int, int>>>& dist, int k, pair<int, int> s, int& ans) {
        if(s.first==m-1 && s.second==n-1) {
            ans=max(ans, dist[m-1][n-1].first);
        }
        visited[s.first][s.second]=true;
        for(int i=0; i<2; i++) {
            int x=s.first+dr[i];
            int y=s.second+dc[i];
            int curCost=0;
            if(isValid(x, y) && grid[x][y]>0) {
                curCost=1;
            }
            if(isValid(x, y) && !visited[x][y] && dist[s.first][s.second].second+curCost<=k && dist[x][y].first<=dist[s.first][s.second].first+grid[x][y]) {
                dist[x][y].first=max(dist[x][y].first, dist[s.first][s.second].first+grid[x][y]);
                dist[x][y].second+=curCost;
                dfs(grid, visited, dist, k, {x, y}, ans);
                dist[x][y].second-=curCost;
            }
        }
        visited[s.first][s.second]=false;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m=grid.size();    
        n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<pair<int, int>>> dist(m, vector<pair<int, int>>(n, {0, 0}));
        int curCost=0;
        if(grid[0][0]>0) {
            curCost=1;
        }
        dist[0][0].first=grid[0][0];
        dist[0][0].second=curCost;
        int ans=-1;
        dfs(grid, visited, dist, k, {0, 0}, ans);
        return ans;
    }
};
