class Solution {
public:
    int min(int x, int y) {
        if(x<y) {
            return x;
        }
        return y;
    }
    int minVertCount(vector<vector<int>>& xCoor, int x, int y) {
        int id=lower_bound(xCoor[x].begin(), xCoor[x].end(), y)-xCoor[x].begin();
        return min(id, xCoor[x].size()-id-1);
    }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> xCoor(n+1);
        vector<vector<int>> yCoor(n+1);
        int size=buildings.size();
        for(int i=0; i<size; i++) {
            xCoor[buildings[i][0]].push_back(buildings[i][1]);
            yCoor[buildings[i][1]].push_back(buildings[i][0]);
        }
        for(int i=0; i<=n; i++) {
            sort(xCoor[i].begin(), xCoor[i].end());
            sort(yCoor[i].begin(), yCoor[i].end());
        }
        int ans=0;
        for(int i=0; i<=n; i++) {
            int minHrzt, minVert;
            int sizeHrzt=yCoor[i].size();
            for(int j=1; j<sizeHrzt-1; j++) {
                minHrzt=min(j, sizeHrzt-j-1);
                minVert=minVertCount(xCoor, yCoor[i][j], i);
                if(minHrzt>0 && minVert>0) {
                    ans++;
                } 
            } 
        }
        return ans;
    }
};
