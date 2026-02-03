class Solution {
    int m, n;
public:
    struct Node{
        int col, row, diag, tDiag;
    };
    bool isContainer(vector<vector<Node>>& prefix, int a, int b, int x, int y) {
        int val=prefix[x+1][y+1].diag-prefix[a][b].diag; 
        if(prefix[x+1][b].tDiag-prefix[a][y+1].tDiag!=val) {
            return false;
        }
        for(int i=a; i<=x; i++) {
            if(prefix[i][y+1].row-prefix[i][b].row!=val) {
                return false;
            }
        }
        for(int i=b; i<=y; i++) {
            if(prefix[x+1][i].col-prefix[a][i].col!=val) {
                return false;
            }
        }
        return true;
    }
    int maxMagicSquare(vector<vector<Node>>& prefix, int i, int j) {
        int maxCount=1;
        int a=i, b=j;
        i++; j++;
        while(i<n && j<m) {
            if(isContainer(prefix, a, b, i, j)) {
                maxCount=max(maxCount, i-a+1);
            }
            i++; j++;
        }   
        return maxCount;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<Node>> prefix(n+1, vector<Node>(m+1, {0, 0, 0}));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                prefix[i+1][j].col=prefix[i][j].col+grid[i][j];
                prefix[i][j+1].row=prefix[i][j].row+grid[i][j];
                prefix[i+1][j+1].diag=prefix[i][j].diag+grid[i][j];
                prefix[i+1][j].tDiag=prefix[i][j+1].tDiag+grid[i][j];
            }
        }        
        int ans=1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans=max(ans, maxMagicSquare(prefix, i, j));
            }
        }
        return ans;
    }
};
