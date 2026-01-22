class Solution {
public:
    void bfs(vector<vector<pair<int, int>>>& adjList, 
            vector<bool>& visited, int& mid, int s) {
        queue<int> q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            for(int i=0; i<adjList[u].size(); i++) {
                int v=adjList[u][i].first;
                int t=adjList[u][i].second;
                if(t>mid && !visited[v]) {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int left=0;
        int right=0;
        vector<vector<pair<int, int>>> adjList(n);
        int u, v, t;
        for(int i=0; i<edges.size(); i++) {
            u=edges[i][0];
            v=edges[i][1];
            t=edges[i][2];
            right=max(right, t);
            adjList[u].push_back({v, t});
            adjList[v].push_back({u, t});
        }
        vector<bool> visited(n, false);
        while(left<=right) {
            visited=vector<bool>(n, false);
            int mid=left+(right-left)/2;
            int count=0;
            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    bfs(adjList, visited, mid, i);
                    count++;
                }
            }
            if(count<k) {
                left=mid+1;
            } else {
                right=mid-1;
            }
        }
        return left;
    }
};
