class Solution {
public:
    struct Cell{
        int height;
        int row;
        int col;
    };
    bool isValid(int N, int M,int x, int y) {
        return x>=0 && y>=0 && x<N && y<M;
    }
    struct option{ 
        bool operator() (const Cell &a, const Cell &b) const {
            return a.height>b.height;
        } 
    };
    int BFS(int N, int M, vector<vector<int>>& heightMap) {
        int total=0;
        priority_queue<Cell, vector<Cell>, option> pq;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        for(int i=0; i<N; i++) {
            pq.push(Cell(heightMap[i][0], i, 0));
            pq.push(Cell(heightMap[i][M-1], i, M-1));
            visited[i][0]=true;
            visited[i][M-1]=true;
        }
        for(int i=0; i<M; i++) {
            pq.push(Cell(heightMap[0][i], 0, i));
            pq.push(Cell(heightMap[N-1][i], N-1, i));
            visited[0][i]=true;
            visited[N-1][i]=true;
        }
        int dr[4]={0, 0, -1, 1};
        int dc[4]={-1, 1, 0, 0};
        int x, y;
        while(!pq.empty()) {
            Cell top=pq.top();
            pq.pop();
            for(int i=0; i<4; i++) {
                x=top.row+dr[i];
                y=top.col+dc[i];
                if(isValid(N, M, x, y) && !visited[x][y]) {
                    if(heightMap[x][y]<top.height) {
                        total+=top.height-heightMap[x][y];
                    }
                    pq.push(Cell(max(heightMap[x][y], top.height), x, y));
                    visited[x][y]=true;
                }
            }
        }
        return total;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int N=heightMap.size();
        int M=heightMap[0].size();
        return BFS(N, M, heightMap);
    }
};
