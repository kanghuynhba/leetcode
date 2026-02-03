class Solution {
public:
    int calc(int upper) {
        int ans=upper;
        for(int i=1; i<upper; i++) {
            ans*=10;
            ans+=upper;
        }
        return ans;
    }
    void extract(vector<int>& digits, int numb) {
        int temp=numb;
        while(numb>0) {
            digits.push_back(temp);
            numb--;
        }
    }
    int convert(vector<int>& digits) {
        int size=digits.size();
        int ans=0;
        for(int i=size-1; i>=0; i--) {
            ans+=digits[size-i-1]*pow(10, i); 
        }
        return ans;
    }
    void perm(int& n, int& minAns, vector<int>& digits, int start) {
        int size=digits.size();
        int curVal;
        for(int i=start; i<size; i++) {
                swap(digits[start], digits[i]);
                perm(n, minAns, digits, i+1);
                curVal=convert(digits);
                if(curVal>n) {
                    minAns=min(minAns, curVal);
                }
                swap(digits[start], digits[i]);
            }
        }
    }
    int nextBeautifulNumber(int n) {
        int upper=1;
        vector<int> digits;
        while(upper<=7) {
            if(n<=calc(upper)) {
                break; 
            }
            upper++;
        }
        int minAns=calc(upper);
        if(upper==1) {
            return calc(upper+1);
        } 
        if(upper==2) {
            return calc(upper);
        }
        if(upper==6) {
            extract(digits, 1);
            extract(digits, 2);
            extract(digits, 3);
            check(n, minAns, digits);
            digits.clear();
        }
        if(upper==7) {
            return 1224444;
        }
        for(int i=1; i<=(upper/2); i++) {
            if(i==upper-i) {
                continue;
            }
            extract(digits, i);                   
            extract(digits, upper-i);                   
            perm(n, minAns, digits, 0);
            digits.clear();
        }
        return minAns;
    }
};
