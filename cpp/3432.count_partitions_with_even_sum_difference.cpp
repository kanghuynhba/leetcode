class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int num : nums) {
            sum+=num;
        }
        int curSum=0, count=0;
        for(int i=0; i<nums.size()-1; i++) {
            curSum+=nums[i];
            if((sum-2*curSum)%2==0) {
                count++;
            }
        }
        return count;
    }
};
