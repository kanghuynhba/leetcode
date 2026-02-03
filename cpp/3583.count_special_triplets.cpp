class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod=1e9+7;
        unordered_map<int, long long> prefix, suffix;        
        long long ans=0;
        for(int i=1; i<nums.size(); i++) {
            suffix[nums[i]]++;
        }
        prefix[nums[0]]++;
        for(int i=1; i<nums.size()-1; i++) {
            suffix[nums[i]]--;
            ans+=(prefix[nums[i]*2]*suffix[nums[i]*2]+mod)%mod;
            ans%=mod;
            prefix[nums[i]]++;
        }
        return ans;
    }
};
