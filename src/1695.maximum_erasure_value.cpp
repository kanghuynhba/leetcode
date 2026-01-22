class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> check;
        vector<int> prefixSum(nums.size(), 0);
        int l=-1; 
        int ans=0, sum=0;
        prefixSum[0]=nums[0];
        for(int i=1; i<nums.size(); i++) {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=0; i<nums.size(); i++) {
            if(check.find(nums[i])!=check.end()) {
                if(check[nums[i]]>=l) {
                    if(l==-1) {
                        sum-=(prefixSum[check[nums[i]]]);
                    } else {
                        sum-=(prefixSum[check[nums[i]]]-prefixSum[l]);
                    }
                    l=check[nums[i]];
                }
            }          
            sum+=nums[i];
            ans=max(ans, sum);
            check[nums[i]]=i;
        }
        return ans;
    }
};
