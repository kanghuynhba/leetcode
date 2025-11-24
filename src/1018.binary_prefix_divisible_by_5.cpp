class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(), false);
        int curNum=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) {
                curNum+=1;
            } 
            if(curNum%5==0) {
                ans[i]=true;
            }
            curNum%=5;
            curNum*=2;
        }
        return ans;
    }
};
