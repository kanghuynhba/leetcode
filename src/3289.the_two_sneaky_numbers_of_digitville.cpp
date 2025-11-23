class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> check(nums.size(), false);
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(check[nums[i]]) {
                ans.push_back(nums[i]);
                if(ans.size()==2) {
                    return ans;
                }
            } else {
                check[nums[i]]=true;
            }
        }
        return ans;
    }
};
