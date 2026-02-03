class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1]>nums[i]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        int minSum, id; 
        while(!isSorted(nums)) {
            minSum=INT_MAX, id=-1;
            for(int i=1; i<nums.size(); i++) {
                if(minSum>nums[i-1]+nums[i]) {
                    minSum=nums[i-1]+nums[i];
                    id=i-1;
                } 
            }
            nums[id]=minSum;
            for(int i=id+1; i<nums.size()-1; i++) {
                nums[i]=nums[i+1];
            }
            nums.pop_back();
            ans++;
        }
        return ans;
    }
};
