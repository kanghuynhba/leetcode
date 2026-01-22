class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> colSum(n+1, vector<int>(m+1, 0)), prefSum(n+1, vector<int>(m+1, 0));        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                colSum[i+1][j]=colSum[i][j]+mat[i][j];
            }
        }
        for(int i=0; i<=n; i++) {
            for(int j=0; j<m; j++) {
                prefSum[i][j+1]=prefSum[i][j]+colSum[i][j];
            }
        }
        int maxSum=0, sum, ans=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cout << prefSum[i][j] << " ";
                for(int k=min(i, j); k>0; k--) {
                    sum=prefSum[i][j]-prefSum[i-k][j]-prefSum[i][j-k]+prefSum[i-k][j-k]; 
                    if(sum<=threshold) {
                        maxSum=max(maxSum, sum);
                        ans=max(ans, k);
                    }
                }
            }
            cout << endl;
        }
        return ans;
    }
};
