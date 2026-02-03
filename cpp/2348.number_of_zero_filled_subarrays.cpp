class Solution {
public:
    long long calc(long long n) {
        return n*(n+1)/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long count=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) {
                count++;
            } else {
                ans+=calc(count);
                count=0;
            }
        }
        ans+=calc(count);
        return ans;
    }
};
