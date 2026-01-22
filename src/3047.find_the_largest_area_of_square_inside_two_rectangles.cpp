class Solution {
public:
    bool isContain(int a, int b, int x1, int y1, int x2, int y2) {
        return (x1<=a && a<=x2) && (y1<=b && b<=y2);
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n=bottomLeft.size();
        int x1, y1, x2, y2;
        int a1, b1, a2, b2;
        long long ans=0, minDiff;
        int maxBlx, maxBly, minTrx, minTry; 
        for(int i=0; i<n; i++) {
            x1=bottomLeft[i][0];
            y1=bottomLeft[i][1];
            x2=topRight[i][0];
            y2=topRight[i][1];
            for(int j=i+1; j<n; j++) {
                a1=bottomLeft[j][0];
                a2=topRight[j][0];
                b1=bottomLeft[j][1];
                b2=topRight[j][1];
                maxBlx=max(a1, x1);
                maxBly=max(b1, y1);
                minTrx=min(x2, a2);
                minTry=min(y2, b2);
                if(isContain(maxBlx, maxBly, a1, b1, a2, b2)
                        && isContain(maxBlx, maxBly, x1, y1, x2, y2) ) {
                        /* && isContain(minTrx, minTry, a1, b1, a2, b2) */
                        /* && isContain(minTrx, minTry, x1, y1, x2, y2) */
                    minDiff=min(abs(maxBlx-minTrx), abs(maxBly-minTry));
                    ans=max(ans, minDiff*minDiff);
                }
            }
        }        
        return ans;
    }
};
