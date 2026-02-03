/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int size=questions.size();
        vector<long long> dp(size+1);
        dp[size]=0;
        for(int i=size-1; i>=0; i--) {
            if(i+questions[i][1]+1<size) {
                dp[i]=max(dp[i+1], dp[questions[i][1]+i+1]+questions[i][0]);
            } else {
                dp[i]=max(dp[i+1], (long long)questions[i][0]);
            }
        }
        return dp[0];
    }
};
// @lc code=end

