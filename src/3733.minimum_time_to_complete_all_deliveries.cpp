class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long vacant0, vacant1, overlap;
        long long low=0, high=1e18;
        long long mid;
        while(low<=high) {
            mid=low+(high-low)/2;
            vacant0=mid-mid/r[0];
            vacant1=mid-mid/r[1];
            overlap=mid-mid/r[0]-mid/r[1]+mid/lcm(r[0], r[1]);
            if(vacant0>=d[0] && vacant1>=d[1] && vacant0+vacant1-overlap>=d[0]+d[1]) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return low;
    }
};
