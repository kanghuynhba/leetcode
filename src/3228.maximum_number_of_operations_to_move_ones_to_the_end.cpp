class Solution {
public:
    int maxOperations(string s) {
        int size=s.size();
        int count=0;
        bool flag=false;
        int factor=1;
        for(int i=size-1; i>=0; i--) {
            if(flag && s[i]=='1') {
                count+=factor; 
                if(i-1>0 && s[i-1]=='0') {
                    factor++; 
                }
            }
            if(s[i]=='0') {
                flag=true;
            }
        }
        return count;
    }
};
