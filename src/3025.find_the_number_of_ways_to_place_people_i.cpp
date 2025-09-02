class Solution {
public:
    static bool option(pair<int, int> &a,pair<int, int> &b) {
        return a.second<b.second || (a.second==b.second && a.first>b.first); 
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int size=points.size();
        vector<pair<int, int>> cdns;
        int ans=0;
        for(int i=0; i<size; i++) {
            cdns.push_back({points[i][0], points[i][1]});
        }
        sort(cdns.begin(), cdns.end(), option);
        int x1, x2, y1, y2, maxNumb;
        for(int i=0; i<size; i++) {
            maxNumb=-1;
            x1=cdns[i].first, y1=cdns[i].second;
            for(int j=i+1; j<size; j++) {
                x2=cdns[j].first, y2=cdns[j].second;
                if(x2<=x1) {
                    if(x2>maxNumb) {
                        maxNumb=x2;
                        ans++;
                    } 
                }
            }
        }
        return ans; 
    }
};
