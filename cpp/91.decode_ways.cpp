class Solution {
public:
    int numDecodings(string s) {
        int ans=0;
        if(s[0]=='0') {
            return 0;
        }
        for(int i=1; i<s.size(); i++) {
            if(s[i-1]=='0' && s[i]=='0') {
                return 0;
            }
            if(s[i-1]=='1') {
                ans+=2;
            }
        }
        return ans;
    }
};
