class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int size=nums.size();
        vector<int> prefix, suffix(size);        
        prefix.push_back(nums[0]);
        suffix[size-1]=nums[size-1];
        for(int i=1; i<size; i++) {
            prefix.push_back(prefix[i-1]+nums[i]);
            suffix[size-i-1]=suffix[size-i]+nums[size-i-1];
        }
        int diff, ans=0;
        for(int i=0; i<size; i++) {
            if(nums[i]==0) {
                diff=abs(suffix[i]-prefix[i]);
                if(diff==0) {
                    ans+=2;
                } else if(diff==1) {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
