class Solution {
private:
    const int dr[4] = {-1, 0, 1, 0}; 
    const int dc[4] = {0, 1, 0, -1};
    int m, n;
public:
    bool isValid(int r, int c) {
        return r<m && c<n && c>=0 && r>=0; 
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& canReach, int r, int c) {
        canReach[r][c] = true;
        
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check if neighbor is valid, not visited, and water can flow TO current cell FROM neighbor
            // (neighbor height >= current height)
            if(isValid(nr, nc) && 
               !canReach[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, canReach, nr, nc);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));
        
        // Start DFS from Pacific border (top row and left column)
        for(int i = 0; i < m; i++) {
            dfs(heights, canReachPacific, i, 0);  // Left column
        }
        for(int j = 0; j < n; j++) {
            dfs(heights, canReachPacific, 0, j);  // Top row
        }
        
        // Start DFS from Atlantic border (bottom row and right column)
        for(int i = 0; i < m; i++) {
            dfs(heights, canReachAtlantic, i, n-1);  // Right column
        }
        for(int j = 0; j < n; j++) {
            dfs(heights, canReachAtlantic, m-1, j);  // Bottom row
        }
        
        // Find cells that can reach both oceans
        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
