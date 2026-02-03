class Solution {
public:
    void formTree(int s, vector<bool>& visited, vector<int>& path, vector<vector<int>>& adjList, vector<vector<int>>& tree) {
        visited[s]=true;
        for(int i=0; i<adjList[s].size(); i++) {
            int neighbor= adjList[s][i];
            if(!visited[neighbor]) {
                formTree(neighbor, visited, path, adjList, tree);
                path[neighbor]=s;
                tree[s].push_back(neighbor);
            }
        }
    }
    void calcAug(int s, vector<vector<int>>& tree, vector<int>& nums, vector<int>& subtreeAug) {
        for(int i=0; i<tree[s].size(); i++) {
            calcAug(tree[s][i], tree, nums, subtreeAug);
            subtreeAug[s]^=subtreeAug[tree[s][i]];
        }
    }
    void dfs1(int a, int& ans, vector<vector<int>>& tree ,vector<int>& subtreeAug, vector<int>& path) {
        for(int i=0; i<tree[a].size(); i++) {
            int b=tree[a][i];
            dfs1(b, ans, tree, subtreeAug, path);         
            vector<int> restAug=vector<int>(subtreeAug.begin(), subtreeAug.end());
            int k=a;
            while(k!=-1) {
                restAug[k]^=subtreeAug[b];
                k=path[k];
            }
            dfs2(ans, subtreeAug[b], 0, 0, b, tree, restAug);
        }
    }
    void dfs2(int& ans, int comp, int s, int a, int except, vector<vector<int>>& tree, vector<int>& subtreeAug) {
        for(int i=0; i<tree[a].size(); i++) {
            int b=tree[a][i];
            if(b!=except) {
                dfs2(ans, comp, s, b, except, tree, subtreeAug);
                pair<int, int> rest={subtreeAug[s]^subtreeAug[b], subtreeAug[b]};
                ans=min(ans, max(comp, max(rest.first, rest.second))-min(comp, min(rest.first, rest.second)));
            }
        }
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> adjList(n);
        vector<vector<int>> tree(n);
        for(int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        vector<int> path(n, -1);
        formTree(0, visited, path, adjList, tree);
        vector<int> subtreeAug= vector<int>(nums.begin(), nums.end());
        calcAug(0, tree, nums, subtreeAug);
        int ans=INT_MAX;
        dfs1(0, ans, tree, subtreeAug, path);
        return ans;
    }
};
