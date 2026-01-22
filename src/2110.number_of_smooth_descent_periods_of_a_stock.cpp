class Solution {
public:
    long long countSum(long long n) {
        return n*(n+1)/2;
    }
    long long getDescentPeriods(vector<int>& prices) {
        int size=prices.size();
        int count=0;
        long long ans=0;
        for(int i=0; i<size-1; i++) {
            if(prices[i]-prices[i+1]==1) {
                count++;
            } else {
                ans+=countSum(count);
                count=0;
            }
        }        
        ans+=countSum(count);
       return ans+size;
    }
};
