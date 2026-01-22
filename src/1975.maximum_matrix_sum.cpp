class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int N=matrix.size(), M=matrix[0].size();
        long long sum=0;
        int count=0;
        int maxNeg=INT_MIN, minPos=INT_MAX;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(matrix[i][j]<=0) {   
                    count++;
                    sum+=(-matrix[i][j]);
                    maxNeg=max(maxNeg, matrix[i][j]);
                } else {
                    sum+=matrix[i][j];
                    minPos=min(minPos, matrix[i][j]);
                }
            }
        }
        if(count%2==1) {
            if(minPos>-maxNeg) {
                sum+=(maxNeg*2);
            } else {
                sum-=(minPos*2);
            }
        }
        return sum;
    }
};

































