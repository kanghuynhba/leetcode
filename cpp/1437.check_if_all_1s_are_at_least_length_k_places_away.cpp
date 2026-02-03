class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int curId=-1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) {
                if(curId!=-1 && i-curId<=k) {
                    return false;
                }
                curId=i;
            }
        }
        return true;
    }
};
