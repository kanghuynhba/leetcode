class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        if(s==t) {
            return 0;
        }
        int n=s.size();
        int countS=0, countT=0;
        for(int i=0; i<n; i++) {
            if(s[i]!=t[i]) {
                if(s[i]=='1') {
                    countS++;
                } 
                if(t[i]=='1') {
                    countT++;
                }
            } 
        }        
        long long ans=0;
        long long minCount=min(countS, countT);
        ans+=minCount*min(swapCost, 2*flipCost);
        countS-=minCount;
        countT-=minCount;
        long long remainder=abs(countS-countT);
        if(remainder%2==1) {
            ans+=flipCost;
            remainder--;
        }
        ans+=min(remainder*flipCost, remainder/2*(swapCost+crossCost));
        return ans; 
    }
};
