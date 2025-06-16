class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int smallest=0, maxDiff=-1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]<nums[smallest]) {
                smallest=i;
            } else if(nums[i]>nums[smallest]) {
                maxDiff=max(maxDiff, nums[i]-nums[smallest]);
            }
        }
        return maxDiff;
    }
};
