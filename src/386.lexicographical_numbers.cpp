class Solution {
public:
    void dfs(vector<int>& ans, int id, int n) {
        if(id>n) {
            return;
        }
        ans.push_back(id);
        for(int i=0; i<10; i++) {
            dfs(ans, id*10+i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<10; i++) {
            dfs(ans, i, n);
        }        
        return ans;
    }
};
