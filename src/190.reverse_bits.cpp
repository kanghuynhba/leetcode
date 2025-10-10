class Solution {
public:
    int reverseBits(int n) {
        int i=0;
        int ans=0;
        while(n) {
            if(n%2==1) {
                ans+=pow(2, 31-i);
            }            
            i++;
            n/=2;
        }
        return ans;
    }
};
