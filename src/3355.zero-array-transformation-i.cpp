/*
 * @lc app=leetcode id=3355 lang=cpp
 *
 * [3355] Zero Array Transformation I
 */

// @lc code=start
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> left, right;
        int n=queries.size();
        for(int i=0; i<n; i++) {
            left.push_back(queries[i][0]);
            right.push_back(queries[i][1]);
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int i=0, j=0;
        while(i<n && j<n) {
            count++;
            if(left[i]<right[j]) {
                
            }
        }
    }
};
// @lc code=end

