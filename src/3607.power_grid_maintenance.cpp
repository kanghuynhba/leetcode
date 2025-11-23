class Solution {
public:
    void bfs(vector<vector<int>>& adjList, 
            vector<priority_queue<int, vector<int>, greater<int>>>& heaps, 
            vector<int>& map, vector<bool>& visited, int s) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        queue<int> q;
        q.push(s);
        minHeap.push(s);
        int size=heaps.size();
        map[s]=size;
        visited[s]=true;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            for(int i=0; i<adjList[u].size(); i++) {
                int v=adjList[u][i];
                if(!visited[v]) {
                    visited[v]=true;
                    minHeap.push(v);
                    map[v]=size;
                    q.push(v);
                }
            }
        }
        heaps.push_back(minHeap);
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<bool> online(c, true);        
        vector<int> map(c, -1);        
        vector<priority_queue<int, vector<int>, greater<int>>> heaps;
        vector<vector<int>> adjList(c);
        vector<bool> visited(c, false);
        for(int i=0; i<connections.size(); i++) {
            int u=connections[i][0]-1;
            int v=connections[i][1]-1;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int i=0; i<c; i++) {
            if(!visited[i]) {
                bfs(adjList, heaps, map, visited, i);
            }
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            int u=queries[i][1]-1;
            if(queries[i][0]==1) {
                if(online[u]) {
                    ans.push_back(u+1);
                } else {
                    while(!heaps[map[u]].empty() && !online[heaps[map[u]].top()]) {
                        heaps[map[u]].pop();
                    }
                    if(heaps[map[u]].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(heaps[map[u]].top()+1);
                    }
                }
            } else {
                online[u]=false;
            }
        }
        return ans;
    }
};
