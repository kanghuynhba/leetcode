class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k=k%size;
        vector<int> key(size);
        for(int i=0; i<=size-1; i++) {
            if(i<k) {
                key[i]=nums[size-k+i];
            } else {
                key[i]=nums[i-k];
            } 
        }
        for(int i=0; i<size; i++) {
            nums[i]=key[i];
        } 
    }
};
