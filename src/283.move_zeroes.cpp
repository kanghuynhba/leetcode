class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        vector<int> arr(size, 0);
        int j=0;
        for(int i=0; i<size; i++) {
            if(nums[i]!=0) {
                arr[j++]=nums[i];
            }
        }
        nums=vector<int>(arr.begin(), arr.end());
    }
};
