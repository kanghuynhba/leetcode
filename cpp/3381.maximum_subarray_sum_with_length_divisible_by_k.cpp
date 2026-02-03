class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefixSum;
        prefixSum.push_back(nums[0]);
        long long ans=INT_MIN;
        for(int i=1; i<nums.size(); i++) {
            prefixSum.push_back(prefixSum[i-1]+nums[i]);
            cout << prefixSum[i] << " ";
        }
        cout << endl;
        return ans;
    }
};
