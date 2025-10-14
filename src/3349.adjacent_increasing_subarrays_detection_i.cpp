class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) {
            return true;
        }
        int maxCount=0, count1, count2;
        int size=nums.size();
        bool flag;
        for(int i=1; i<size-k+1; i++) {
            count1=0, count2=0;
            flag=false;
            for(int j=i; j<k+i; j++) {
                if(nums[j-1]<nums[j]) {
                    count1++;
                    if(count1>=k-1) {
                        flag=true;
                    }
                } else {
                    count1=0;
                    flag=false;
                }
                if(j+k-1>=size) {
                    continue;
                }
                if(nums[j+k-2]<nums[j+k-1]) {
                    count2++;
                    if(count2>=k-1 && flag) {
                        return true;
                    }
                } else {
                    count2=0;
                }
            }
        }
        return false;
    }
};
