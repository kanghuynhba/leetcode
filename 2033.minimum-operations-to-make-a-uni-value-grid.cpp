/*
 * @lc app=leetcode id=2033 lang=cpp
 *
 * [2033] Minimum Operations to Make a Uni-Value Grid
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int minNumb=grid[0][0];
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                minNumb=min(minNumb, grid[i][j]);
            }
        }       
        int mid=n*m/2;
        int countSmaller=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]<=minNumb)
            }
        }
    }
}; 
// @lc code=end

