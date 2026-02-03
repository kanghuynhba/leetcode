class Solution {
    int dr[2]={1, 0};
    int dc[2]={0, 1};
    int m, n;
public:
    struct Node {
        int x, y;
    };
    bool isValid(Node node) {
        return node.x>=0 && node.y>=0 && node.x<m && node.y<n;
    }
    void dfs(vector<vector<int>>& grid, 
            int& k, Node curNode, int curMod, int& count) {
        if(curNode.x==m-1 && curNode.y==n-1) {
            if(curMod==0) {
                count++;
            }
            return;
        }
        for(int i=0; i<2; i++) {
            Node neighbor={curNode.x+dr[i], curNode.y+dc[i]};
            if(isValid(neighbor)) {
                dfs(grid, k, neighbor, 
                        (curMod+grid[neighbor.x][neighbor.y])%k, count);
            }
        }
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size(); 
        n=grid[0].size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count=0;
        dfs(grid, k, {0, 0}, grid[0][0]%k, count);
        return count;
    }
};
