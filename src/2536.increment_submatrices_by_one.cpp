class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(int i=0; i<queries.size(); i++) {
            for(int j=queries[i][0]; j<=queries[i][2]; j++) {
                diff[j][queries[i][1]]+=1;
                if(queries[i][3]+1<n) {
                    diff[j][queries[i][3]+1]-=1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j-1>=0) {
                    ans[i][j]=ans[i][j-1];
                }                 
                ans[i][j]+=diff[i][j];
            }
        }
        return ans;
    }
};
