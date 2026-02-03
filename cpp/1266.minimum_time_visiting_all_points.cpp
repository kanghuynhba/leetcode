class Solution {
public:

    int minTime(vector<int>& point1, vector<int>& point2) {
        return max(abs(point1[0]-point2[0]), abs(point1[1]-point2[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0; i<points.size()-1; i++) {
            ans+=minTime(points[i], points[i+1]);
        } 
        return ans;
    }
};
