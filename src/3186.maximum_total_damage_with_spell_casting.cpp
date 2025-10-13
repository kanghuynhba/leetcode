class Solution {
public:
    long long max(long long x, long long y) {
        if(x>y) {
            return x;
        }
        return y;
    }
    long long maximumTotalDamage(vector<int>& power) {
        int size=power.size();
        unordered_map<int, long long>count, prefix;
        long long ans=0;
        int power1, power2, id;
        sort(power.begin(), power.end());
        for(int i=0; i<size; i++) {
            if(prefix.find(power[i])!=prefix.end()) {
                count[power[i]]+=power[i];
                prefix[power[i]]=max(prefix[power[i]], count[power[i]]);
            } else {
                count[power[i]]=power[i];
                prefix[power[i]]=power[i];
            }
            power1=power[i]-1;
            power2=power[i]-2;
            id=lower_bound(power.begin(), power.end(), power[i]-2)-power.begin()-1;
            /* while(id>=0 && power[id]>=power2) { */
            /*     id--; */ 
            /* } */
            if(id>=0 && power[id]<power2) {
                prefix[power[i]]=max(prefix[power[i]], count[power[i]]+prefix[power[id]]);
            } 
            prefix[power[i]]=max(prefix[power[i]], max(prefix[power1], prefix[power2]));
            ans=max(ans, prefix[power[i]]);
        }
        return ans;
    }
};
