class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int size=nums.size();
        int maxCount=0;
        for(int i=0; i<size; i++) {
            unordered_set<int> countOdd, countEven;
            for(int j=i; j<size; j++) {
                if(nums[j]%2==1) {
                    countOdd.insert(nums[j]);
                } else {
                    countEven.insert(nums[j]);
                }
                if(countOdd.size()==countEven.size()) {
                    maxCount=max(maxCount, j-i+1);
                }
            }
        }        
        return maxCount;
    }
};
