class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int size=nums.size();
        int lower, upper;
        int ans=0;
        for(int i=0; i<size; i++) {
            lower=lower_bound(nums.begin(), nums.end(), nums[i]-k)-nums.begin();
            upper=lower_bound(nums.begin(), nums.end(), nums[i]-k+1)-nums.begin();
            if(upper<size && (upper-i+1<=numOperations || upper-lower<=numOperations)) {
                ans=max(ans, i-lower+1); 
            }
        }
        return ans;
    }
};
