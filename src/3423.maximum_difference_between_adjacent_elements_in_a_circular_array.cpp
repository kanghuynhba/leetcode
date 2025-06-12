class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff=0, size=nums.size();
        for(int i=0; i<size-1; i++) {
              maxDiff=max(maxDiff, abs(nums[i]-nums[i+1]));
        }
        return max(maxDiff, abs(nums[0]-nums[size-1]));
    }
};
