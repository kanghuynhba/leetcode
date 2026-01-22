class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) {
            return -1;
        }
        int remainder=0;
        int pre=1;
        int count=0;
        while(count<k) {
            pre=(pre*10)%k;
            remainder+=pre;
            remainder%=k;
            count++;
            if(remainder==0) {
                return count;
            }
        }
        return -1;
    }
};

