/*
 * @lc app=leetcode id=2900 lang=cpp
 *
 * [2900] Longest Unequal Adjacent Groups Subsequence I
 */

// @lc code=start
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        ans.push_back(words[0]);
        int diff=groups[0];
        for(int i=1; i<groups.size(); i++) {
            if(diff!=groups[i]) {
                ans.push_back(words[i]);
                diff=groups[i];
            } 
        }       
        return ans;
    }
};
// @lc code=end

