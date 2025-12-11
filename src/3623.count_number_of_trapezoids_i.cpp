class Solution {
    const int mod=1e9+7;
public:
    int calcLine(long long countPoint) {
        return countPoint%mod*(countPoint-1)%mod/2;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> count;
        int x, y;
        for(int i=0; i<points.size(); i++) {
            x=points[i][0];
            y=points[i][1];
            count[y]++;
        }
        long long ans=0, countLines=0;
        int numbPoints;
        for(auto it=count.begin(); it!=count.end(); it++) {
            numbPoints=it->second;
            if(numbPoints>1) {
                ans+=(countLines*calcLine(numbPoints));
                countLines+=calcLine(numbPoints);
                countLines%=mod;
                ans%=mod;
            }
        }
        return ans;
    }
};
