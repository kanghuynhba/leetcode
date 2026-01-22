class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row=strs[0].size();        
        int col=strs.size();
        int ans=0;
        int ch;
        for(int i=0; i<row; i++) {
            ch=strs[0][i];
            for(int j=1; j<col; j++) {
                if(ch>strs[j][i]) {
                    ans++;
                    break;
                } else {
                    ch=strs[j][i];
                }
            }
        }
        return ans;
    }
};
