/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

// @lc code=start
class Solution {
public:
    struct option{
        bool operator() (const pair<int, long long>& a,const pair<int, long long>& b) const {
            return a.second>b.second;
        }
    };
    void dijkstra(vector<vector<pair<int, long long>>>& graph, vector<int>& pairCount, int s) {
        const int MOD=1e9+7;
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, option> pq;
        vector<long long> dist(graph.size(), LLONG_MAX);
        dist[s]=0;
        pairCount[s]=1;
        pq.push({s, 0});
        while(!pq.empty()) {
            int u=pq.top().first;
            long long w=pq.top().second;
            pq.pop();
            if(dist[u]!=w) {
                continue;
            }
            for(int i=0; i<graph[u].size(); i++) {
                pair<int, long long> neighbor=graph[u][i];
                if(dist[neighbor.first]>w+neighbor.second) {
                    dist[neighbor.first]=w+neighbor.second;
                    pq.push({neighbor.first, dist[neighbor.first]});
                    pairCount[neighbor.first]=pairCount[u];
                } else if(dist[neighbor.first]==w+neighbor.second) {
                    pairCount[neighbor.first]=(pairCount[neighbor.first]+pairCount[u])%MOD;
                }
            }
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> graph(n);
        vector<int> pairCount(n, 0);
        int u, v;
        long long w;
        for(int i=0; i<roads.size(); i++) {
            u=roads[i][0];
            v=roads[i][1];
            w=roads[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        dijkstra(graph, pairCount, 0);
        return pairCount[n-1];
    }
};
// @lc code=end

