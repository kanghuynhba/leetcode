class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans=vector<vector<int>>(numRows);
        for(int i=0; i<numRows; i++) {
            ans[i].push_back(1);
            if(i>=1) {
                for(int j=0; j<ans[i-1].size(); j++) {
                    if(j==ans[i-1].size()-1) {
                        ans[i].push_back(1);
                        break;
                    } 
                    ans[i].push_back(ans[i-1][j]+ans[i-1][j+1]);
                }
            }
        }
        return ans;
    }
};
