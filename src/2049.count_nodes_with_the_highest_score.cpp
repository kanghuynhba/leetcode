class Solution {
public:
    void dfs(vector<vector<int>>& adjList, 
            vector<int>& subtree, 
            unordered_map<long long, int>& count, 
            int curNode) {
        int n=adjList.size();
        long long product=1, rest=n-1;
        for(int i=0; i<adjList[curNode].size(); i++) {
            int child=adjList[curNode][i];
            dfs(adjList, subtree, count, child);
            subtree[curNode]+=subtree[child];
            product*=subtree[child];
            rest-=subtree[child];
        }
        if(rest==0) {
            rest=1;
        }
        count[product*rest]++;
        subtree[curNode]++;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>> adjList(n);
        vector<int> subtree(n, 0);
        unordered_map<long long, int> countBest;
        for(int i=1; i<n; i++) {
            adjList[parents[i]].push_back(i);
        }
        dfs(adjList, subtree, countBest, 0);
        long long best=0, count;
        for(auto it=countBest.begin(); it!=countBest.end(); it++) {
            if(it->first>best) {
                best=it->first;
                count=it->second;
            }
        }
        return count;
    }
};
