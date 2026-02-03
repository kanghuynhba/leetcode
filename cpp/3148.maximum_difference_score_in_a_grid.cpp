class Solution {
    int m,n;
public:
    bool isValid(int r, int c) {
        return r<m && c<n;
    }
    int maxScore(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dist(m, vector<int> (n, -1e9-7));         
        int diff;
        int ans=INT_MIN;
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(i==m-1 && j==n-1) {
                    continue;
                }            
                if(isValid(i, j+1)) {
                    diff=grid[i][j+1]-grid[i][j];
                    dist[i][j]=max(dist[i][j+1]+diff, diff);
                }
                if(isValid(i+1, j)) {
                    diff=grid[i+1][j]-grid[i][j];
                    dist[i][j]=max(dist[i][j], max(dist[i+1][j]+diff, diff));
                }
                ans=max(ans, dist[i][j]);
            }
        }
        return ans;
    }
};





























































































































































