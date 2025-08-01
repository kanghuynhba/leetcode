class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int countOdd=0, countEven=0;
        for(int i=0; i<nums.size()-1; i++) {
            if((nums[i]+nums[i+1])%2==1) {
                countOdd++;
            } else {
                countEven++;
            }
        }
        return max(countOdd, countEven)+1;
    }
};
