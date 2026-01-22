class Solution {
    const int mod=1e9+7;
public:
    long long calcSeq(long long n) {
        return n%mod*n%mod;
    }
    unordered_set<int> check(vector<int> fences, int n) {
        unordered_set<int> checkList;
        fences.push_back(1);
        fences.push_back(n);
        int size=fences.size();
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                checkList.insert(abs(fences[i]-fences[j]));
            }
        }
        return checkList;
    }
    long long max(long long a, long long b) {
        if(a<b) {
            return b;
        }
        return a;
    }
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> h=check(hFences, m); 
        unordered_set<int> v=check(vFences, n);
        long long ans=-1;
        for(auto it : h) {
            if(v.contains(it)) {
                ans=max(ans, it);
            }
        }
        if(ans==0) {
            return -1;
        }
        return calcSeq(ans);
    }
};
