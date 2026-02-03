class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        int total, preTotal=0;
        int ans=0;
        for(int i=0; i<n; i++) {
            total=0;
            for(int j=0; j<m; j++) {
                if(bank[i][j]=='1') {
                    total++;
                }
            }
            ans+=(total*preTotal);
            if(total!=0) {
                preTotal=total;
            }
        }        
        return ans;
    }
};
