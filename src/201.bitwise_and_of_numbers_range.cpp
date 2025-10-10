class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=left;
        int prevAns;
        for(int i=left; i<=right; i++) {
            prevAns=ans;
            ans&=i;
            if(i==INT_MAX) {
                break;
            }
            if(prevAns==ans) {
                return prevAns;
            } 
        }       
        return prevAns;
    }
};
