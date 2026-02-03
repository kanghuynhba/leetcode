/*
 * @lc app=leetcode id=3337 lang=cpp
 *
 * [3337] Total Characters in String After Transformations II
 */

// @lc code=start
class Solution {
public:
    long long dfs(vector<vector<long long>>& dp, vector<int>& count, int t, char ch) {
        int pos=ch-'a';
        const int mod=1e9+7;
        for(int i=pos+1; i<=pos+dp[0][ch-'a']; i++) {
            if(dp[t-1][count[i]]==0) {
                dp[t][pos]+=dfs(dp, count, t-1, char(count[i]+'a'))%mod;
            } else {
                dp[t][pos]+=dp[t-1][count[i]]%mod;
            }
        }
        return dp[t][pos]%mod;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> dp(t, vector<long long>(26, 0));
        vector<int> count(52, 0);
        for(int i=0; i<52; i++) {
            count[i]=i;
            if(count[i]>=26) {
                count[i]-=26;
            }
        }
        for(int i=0; i<26; i++) {
            dp[0][i]=nums[i];
        }
        const int mod=1e9+7;
        long long ans=0;
        for(int i=0; i<s.size(); i++) {
            if(dp[t-1][s[i]-'a']==0) {
                ans+=dfs(dp, count, t-1, s[i])%mod;
            } else {
                ans+=dp[t-1][s[i]-'a']%mod;
            }
        }
        return ans%mod;
    }  
};
// @lc code=end

