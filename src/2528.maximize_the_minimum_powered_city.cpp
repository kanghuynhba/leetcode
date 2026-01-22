class Solution {
public:
    long long min(long long a, long long b) {
        if(a<b) {
            return a;
        }
        return b;
    }
    bool check(vector<long long> diff, long long mid, int k, int r) {
        long long sum=0;
        long long add;
        int end;
        int size=diff.size();
        int n=size-1;
        for(int i=0; i<n; i++) {
            sum+=diff[i];
            if(sum<mid) {
                add=mid-sum;
                k-=add;
                if(k<0) {
                    return false;
                }
                end=min(n, i+2*r+1);
                diff[end]-=add;
                sum+=add;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int size=stations.size();
        vector<long long> prefixSum;
        vector<long long> rangeSum(size);
        vector<long long> diff(size+1, 0);
        prefixSum.push_back(0);
        long long sum=0;
        for(int i=1; i<=size; i++) {
            sum+=stations[i-1];
            prefixSum.push_back(prefixSum[i-1]+stations[i-1]);
        }
        int pre, suf;
        long long left=INT_MAX;
        for(int i=0; i<size; i++) {
            pre=max(0, i-r);
            suf=min(size, i+r+1);
            rangeSum[i]=prefixSum[suf]-prefixSum[pre];
            left=min(left, rangeSum[i]);
        }
        diff[0]=rangeSum[0];
        for(int i=1; i<size; i++) {
            diff[i]=rangeSum[i]-rangeSum[i-1];
        }
        diff[size]=-rangeSum[size-1];
        long long right=sum+k;
        long long ans=0;
        while(left<=right) {
            long long mid=left+(right-left)/2;
            if(check(diff, mid, k, r)) {
                ans=mid;
                left=mid+1; 
            } else {
                right=mid-1;
            }
        }
        return ans;
    }
};
