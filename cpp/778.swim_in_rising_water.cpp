class Solution {
    int n;
    const int dr[4]={-1,0,1,0};
    const int dc[4]={0,1,0,-1};
public:
    struct Node {
        int r, c;
    };
    struct option{
        bool operator() (const pair<int, Node>& a, const pair<int, Node>& b) const {
            return a.first>b.first;
        }
    };
    bool isValid(int r, int c) {
        return r>=0 && c>=0 && r<n && c<n;
    }
    int dijkstra(vector<vector<int>>& grid, Node s) {
        priority_queue<pair<int, Node>, vector<pair<int, Node>>, option> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[s.r][s.c]=grid[s.r][s.c];
        visited[s.r][s.c]=true;
        pq.push({dist[s.r][s.c], s});
        int nr, nc;
        while(!pq.empty()) {
            Node curNode=pq.top().second;
            int curDist=pq.top().first;
            pq.pop();
            if(curNode.r==n-1 && curNode.c==n-1) {
                return curDist;
            }
            for(int i=0; i<4; i++) {
                nr=curNode.r+dr[i];
                nc=curNode.c+dc[i];
                if(isValid(nr, nc) && !visited[nr][nc] && max(curDist, grid[nr][nc])<dist[nr][nc]) {
                    dist[nr][nc]=max(curDist, grid[nr][nc]);
                    visited[nr][nc]=true;
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
        return -1;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        return dijkstra(grid, {0, 0}); 
    }
};
