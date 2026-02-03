class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int maxCount=1;        
        int size=nums.size();
        int prevCount=0, curCount=1;
        for(int i=1; i<size; i++) {
            if(nums[i-1]<nums[i]) {
                curCount++; 
                maxCount=max(maxCount, curCount/2);
                if(curCount<=prevCount) {
                    maxCount=max(maxCount, curCount);
                }
            } else {
                prevCount=curCount;
                curCount=1;
            }
        }
        return maxCount;
    }
};
