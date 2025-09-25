class Solution {
public:
    void dfs(unordered_map<int, int>& counter, vector<int>& comb, int size, vector<vector<int>>& ans) {
        if(comb.size()==size) {
            ans.push_back(comb);
            return;
        }
        for(auto &item : counter) {
            int num=item.first;
            int count=item.second;
            if(count==0) {
                continue;
            }
            counter[num]--;
            comb.push_back(num);
            dfs(counter, comb, size, ans);
            comb.pop_back();
            counter[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        unordered_map<int, int> counter;
        for(int num : nums) {
            counter[num]++;
        }
        dfs(counter, comb, nums.size(), ans);                
        return ans;
    }
};
