class Solution {
    int n;
public:
    void bfs(vector<vector<int>>& graph, vector<int>& path, int s) {
        queue<int> q;
        vector<bool> visited(n, false);
        visited[s]=true;
        q.push(s);
        int u, nu;
        while(!q.empty()) {
            u=q.front();
            q.pop();
            for(int i=0; i<graph[u].size(); i++) {
                nu=graph[u][i];
                if(!visited[nu]) {
                    visited[nu]=true;
                    q.push(nu);
                    path[nu]=u;
                }
            }
        }
    }
    long long factorization(long long n) {
        int count=0;
        long long ans=1;
        if(n%2==0) {
            while(n%2==0) {
                n/=2;
                count++;
            }
            if(count%2==1) {
                ans*=2;
            }
        }
        for(int i=3; i<=sqrt(n); i+=2) {
            count=0;
            while(n%i==0) {
                n/=i;
                count++;
            }
            if(count%2==1) {
                ans*=i;
            }
        }
        if(n>2) {
            ans*=n;
        }
        return ans;
    }
    bool checkPath(vector<int>& path, int s, int t) {
        while(s!=-1) {
            if(s==t) {
                return true;
            }
            s=path[s];
        } 
        return false;
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        this->n=n;
        unordered_map<int, vector<int>> mp;        
        vector<vector<int>> graph(n);
        vector<int> path(n, -1);
        int u, v;
        for(int i=0; i<edges.size(); i++) { 
            u=edges[i][0];
            v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs(graph, path, 0);
        vector<long long>fact(n, 1);
        for(int i=0; i<n; i++) {
            fact[i]=factorization(nums[i]);
        }
        long long curVal;
        long long ans=0;
        for(int i=0; i<n; i++) {
            curVal=fact[i];
            for(int j=0; j<mp[curVal].size(); j++) {
                if(checkPath(path, i, mp[curVal][j])) {
                    ans++;
                }
            }        
            mp[curVal].push_back(i);
        }
        cout << endl;
        return ans;
    }
};
