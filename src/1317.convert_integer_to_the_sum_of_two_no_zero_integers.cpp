class Solution {
public:
    int subNum(int n) {
        int numb=0;
        int cnt=0;
        do {
            if(n%10==0) {
                numb+=pow(10, cnt);
            }
            cnt++;
            n/=10;
        } while(n);
        return numb;
    }
    int cntDigit(int n) {
        int cnt=0;
        while(n) {
            cnt++;
            n/=10;
        }
        return cnt;
    }
    vector<int> getNoZeroIntegers(int n) {
        if(n<=9) {
            return {n-1, 1};
        } 
        int cnt=cntDigit(n);
        int first=0;
        for(int i=1; i<cnt; i++) {
            first*=10;
            first+=9;
        }
        int sub=subNum(n-first);
        return {first-sub, n-first+sub}; 
    }
};
