/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start
class Solution {
public:
    void dfs(int s, vector<vector<int>>& graph, vector<bool>& visited, bool& flag) {
        visited[s]=true;
        int size=graph[s].size();
        for(int i=0; i<size; i++) {
            int v=graph[s][i];
            if(!visited[v]) {
                if(graph[v].size()==size) {
                    dfs(v, graph, visited, flag);
                } else {
                    flag=false;
                    return;
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        int u, v;
        for(int i=0; i<edges.size(); i++) {
            u=edges[i][0];
            v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }       
        bool flag=true;
        int count=0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, flag);
                if(flag) {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

