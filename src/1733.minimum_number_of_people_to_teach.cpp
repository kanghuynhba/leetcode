class Solution {
public:
    void dfs(int& cur, int person, int language, 
            vector<vector<bool>>& learned, 
            vector<vector<int>>& adjList,
            vector<bool>& visited) {
        if(!learned[language][person]) {
            cur++;
            learned[language][person]=true;
        }
        visited[person]=true;
        for(int i=0; i<adjList[person].size(); i++)  {
            int neighbor=adjList[person][i];
            if(!learned[language][neighbor]) {
                cur++;
                learned[language][neighbor]=true;
            }
            if(!visited[neighbor]) {
                dfs(cur, neighbor, language, learned, adjList, visited); 
            }
        }
        learned[language][person]=false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int ans=INT_MAX;
        int m=languages.size();
        vector<vector<int>> adjList(m);
        vector<vector<bool>> learned=
            vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0; i<friendships.size(); i++) {
            int u=friendships[i][0];
            int v=friendships[i][1];
            adjList[u-1].push_back(v-1);
            adjList[v-1].push_back(u-1);
        }
        for(int i=0; i<m; i++) {
            for(int j=0; i<languages.size(); i++) {
                learned[i][languages[i][j]]=true;
            }
        }
        for(int i=0; i<n; i++) {
            vector<bool> visited(m, false);
            int curPpl=0;
            dfs(curPpl, 0, i, learned, adjList, visited);
            ans=min(ans, curPpl);      
        }
        return ans;        
    }
};
