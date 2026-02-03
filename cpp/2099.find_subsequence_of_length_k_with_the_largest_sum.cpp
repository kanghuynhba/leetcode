class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexed_nums;        
        int size=nums.size();
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++) {
            indexed_nums.push_back({nums[i], i});
        }
        sort(indexed_nums.begin(), indexed_nums.end());
        vector<int> result;
        for (int i = size - 1; i >= size - k; i--) {
            visited[indexed_nums[i].second] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
