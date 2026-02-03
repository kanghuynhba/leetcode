class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int count = 0, nextId;        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            nextId=upper_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin()-1;     
            count++;
            i = nextId+1; // Move to the next partition start
        }
        return count;
    }
};
