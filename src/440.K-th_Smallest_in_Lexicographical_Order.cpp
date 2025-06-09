class Solution {
public:
    int findKthNumber(int n, int k) {
        long cur=1, steps;
        long i=1;
        while(i<k) {
            steps=countStep(cur, n);
            if(i+steps<=k) {
                cur++;
                i+=steps;
            } else {
                cur*=10;
                i++;
            }
        }
        return cur;
    }
    long countStep(long cur, int n) {
        long res=0;
        long neighbor=cur+1;
        while(cur<=n) {
            neighbor=min(neighbor, (long)n+1);
            res+=neighbor-cur;
            cur*=10;
            neighbor*=10; 
        }
        return res;
    }
};
