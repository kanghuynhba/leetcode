class Solution {
    const int mod=1e9+7;
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int size=nums.size();
        long long ans=0;
        unordered_map<int, pair<long long, long long>> dp;
        for(int i=0; i<nums.size(); i++) {
            dp[nums[i]].second%=mod;
            dp[nums[i]].second+=(dp[nums[i]-1].second%mod+(dp[nums[i]-1].first%mod*nums[i]%mod)%mod+nums[i])%mod;
            dp[nums[i]].second%=mod;
            dp[nums[i]].second+=(dp[nums[i]+1].second%mod+(dp[nums[i]+1].first%mod*nums[i]%mod)%mod)%mod;
            dp[nums[i]].first+=dp[nums[i]-1].first%mod+dp[nums[i]+1].first%mod+1;
        }
        for(auto it=dp.begin(); it!=dp.end(); it++) {
            ans+=it->second.second%mod;
            ans%=mod;
        }
        return ans;
    }
};
