/*
 * @lc app=leetcode id=2503 lang=cpp
 *
 * [2503] Maximum Number of Points From Grid Queries
 */

// @lc code=start
class Solution {
public: 
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        return x>=0 && y>=0 && x<grid.size() && y<grid[0].size();
    }
    void bfs(vector<vector<int>>& grid, vector<pair<int, int>>& queries, vector<int>& ans) {
        queue<pair<int, int>> q;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int ,int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0]=true;
        int count=0;
        int dr[]={1, -1, 0, 0};
        int dc[]={0, 0, 1, -1};
        pair<int, int> tempFront;
        for(int i=0; i<queries.size(); i++) {
            while(!minHeap.empty() && queries[i].first>minHeap.top().first) {
                q.push(minHeap.top().second);
                minHeap.pop();
            }
            while(!q.empty()) { 
                pair<int, int> front=q.front();
                if(queries[i].first>grid[front.first][front.second]) {
                    count++;
                }
                q.pop();
                for(int k=0; k<4; k++) {
                    int x=front.first+dr[k];
                    int y=front.second+dc[k];
                    if(isValid(grid, x, y) && !visited[x][y]) {
                        visited[x][y]=true;
                        if(queries[i].first>grid[x][y]) {
                            q.push({x, y});
                        } else {
                            minHeap.push({grid[x][y], {x, y}});
                        }
                    }
                }
            }
            ans[queries[i].second]=count;
        }
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int>> sortedQueries;
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        bfs(grid, sortedQueries, ans);
        return ans;
    }
};
// @lc code=end

