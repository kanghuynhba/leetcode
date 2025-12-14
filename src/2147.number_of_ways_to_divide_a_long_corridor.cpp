class Solution {
public:
    int numberOfWays(string corridor) {
        int size=corridor.size();
        long long ans=1;
        int sum=0;
        int count=1;
        const int mod=1e9+7;
        for(int i=0; i<size; i++) {
            if(corridor[i]=='S') {
                if(sum%2==0 && sum>0) {
                    ans=ans%mod*count%mod; 
                }
                count=1;
                sum++;
            } else {
                count++;
            }
            
        }
        if(sum%2==1 || sum==0) {
            return 0;
        }
        return ans%mod;
    }
};
