class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans=0;
        const int mod=1e9+7;
        vector<int> dp(nums.size(),0);
        dp[0]=1;
        for(int i=1; i<nums.size(); i++) {
            dp[i]=(dp[i-1]*2)%mod;
        }
        for(int i=0; i<nums.size(); i++) {
            int maxId=upper_bound(nums.begin(), nums.end(), target-nums[i])-nums.begin()-1;
            if(maxId>=i) {
                ans=(ans+dp[maxId-i])%mod;
            } else {
                break;
            }
        }
        return ans%mod;
    }
};

