/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> check;
        for(int i=0; i<nums.size(); i++) {
            if(check.find(nums[i])!=check.end()) {
                return {check[nums[i]], i};
            } else {
                check[target-nums[i]]=i;
            }
        }
        return {};
    }
};
// @lc code=end

