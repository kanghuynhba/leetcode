class Solution {
public:
    int numSub(string s) {
        const int mod=1e9+7;
        long long count=0;
        long long ans=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') {
                count++;
            } else {
                ans+=count*(count+1)/2;
                ans%=mod;
                count=0;
            }
        }
        ans+=count*(count+1)/2;
        ans%=mod;
        return ans;
    }
};
