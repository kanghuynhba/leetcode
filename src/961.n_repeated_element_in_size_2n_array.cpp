class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> check;
        for(int i=0; i<nums.size(); i++) {
            if(check.find(nums[i])!=check.end()) {
                return nums[i];
            }
            check.insert(nums[i]);
        }
        return -1;
    }
};
