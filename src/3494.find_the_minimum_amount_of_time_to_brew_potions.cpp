class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();       
        int m=mana.size();       
        vector<long long> startTime(m, 0);
        long long cur, prev, sum=0, curSum;
        for(int i=0; i<n; i++) {
            sum+=skill[i];
        }
        for(int i=1; i<m; i++) {
            curSum=sum;
            for(int j=n-1; j>=0; j--) {
                prev=startTime[i-1]+curSum*mana[i-1];
                if(j==n-1) {
                    cur=prev;
                } else {
                    cur-=(skill[j]*mana[i]);
                    if(cur<prev) {
                        cur=prev;
                    }
                }
                curSum-=skill[j];
            }
            startTime[i]=cur;
        }
        return startTime[m-1]+sum*mana[m-1];
    }
};
