class Solution {
public:
    int smallest(int num) {
        if(num==2) {
            return -1;
        }
        int a;
        for(int i=0; i<num; i++) {
            a=i|(i+1);
            if(a==num) {
                return i;
            }
        }
        return -1;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            ans.push_back(smallest(nums[i])); 
        }        
        return ans;
    }
};
