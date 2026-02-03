class Solution {
public:
    int smallest(int num) {
        if(num==2) {
            return -1;
        }
        int a, x;
        for(int i=log2(num); i>=0; i--) {
            x=pow(2, i);
            if(num&x==x) {
                a=(num-x)|(num-x+1);
                if(a==num) {
                    return num-x;
                }
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
