class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),  nums.end());        
        int j=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++) {
            while(j<i && (nums[i]-nums[j]>1)) {
                j++;
            }
            if(nums[i]-nums[j]==1) {
                ans=max(ans, i-j+1);
            }
        }
        return ans;
    }
};
