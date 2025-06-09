/*
 * @lc app=leetcode id=2901 lang=cpp
 *
 * [2901] Longest Unequal Adjacent Groups Subsequence II
 */

// @lc code=start
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int> dp(n, 0);
        vector<int> path(n, -1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(words[i].size()==words[j].size() && dp[i]+1>dp[j] && groups[i]!=groups[j]) {
                    bool flag=false;
                    for(int k=0; k<words[i].size(); k++) {
                        if(words[i][k]!=words[j][k]) {
                            if(flag) {
                                flag=false;
                                break;
                            }
                            flag=true;
                        }
                    }
                    if(flag) {
                        dp[i]=dp[j]+1;
                        path[i]=j;
                    }
                }
            }
        }
        int maxCount=0;
        int id=-1;
        for(int i=0; i<n; i++) {
            if(maxCount<dp[i]) {
                maxCount=dp[i];
                id=i;
            }
        }
        vector<string> ans;
        for(int i=id; i>=0; i=path[i]) {
            ans.push_back(words[i]);
        }           
        return ans;
    }
};
// @lc code=end

