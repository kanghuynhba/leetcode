class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int size=nums.size();
        vector<int> dp(size, 0);
        unordered_map<int, int> counter;
        for(int i=0; i<size; i++) {
            if(nums[i]%2==1) {
                dp[i]=-1;
            } else {
                dp[i]=1;
            }
            if(counter.find(nums[i])!=counter.end()) {
                dp[counter[nums[i]]]=0;
            }
            counter[nums[i]]=i;
        }        
        vector<int> preSum;
        preSum.push_back(0);
        for(int i=0; i<size; i++) {
            preSum.push_back(preSum[i]+dp[i]);
        }
        unordered_map<int, int> check;
        int ans=0;
        for(int i=0; i<=size; i++) {
            if(check.find(preSum[i])==check.end()) {
                check[preSum[i]]=i;
            } else {
                ans=max(ans, i-check[preSum[i]]);
            }
        }
        return ans;
    }
};
