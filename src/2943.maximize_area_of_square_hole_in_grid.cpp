class Solution {
public:
    int maxConsec(vector<int> sortBar) {
        int maxCount=1, count=1;
        for(int i=1; i<sortBar.size(); i++) {
            if(sortBar[i-1]==sortBar[i]-1) {
                count++;
                maxCount=max(maxCount, count);
            } else {
                count=1;
            }
        }
        return maxCount;
    }
    int calcSeq(int n) {
        int sum=1, ele=1;
        for(int i=1; i<=n; i++) {
            ele+=2;
            sum+=ele;
        }
        return sum;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxHConsec=maxConsec(hBars);
        int maxVConsec=maxConsec(vBars);
        return calcSeq(min(maxHConsec, maxVConsec)); 
    }
};
