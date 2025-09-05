class Solution {
public:
    int countBit(long long x) {
        int count=0;    
        while(x>0) {
            count+=x&1;
            x=x>>1;
        }
        return count;
    }
    int makeTheIntegerZero(int num1, int num2) {
        if(num2>=num1) {
            return -1;
        }
        int count=1;
        long long n1=num1, n2=num2;
        int bit=countBit(n1-n2*count);
        while(count<bit) {
            count++;
            bit=countBit(n1-n2*count);
            if(bit>=n1-n2*count){
                return -1;
            }
        }
        return count;
    }
};
