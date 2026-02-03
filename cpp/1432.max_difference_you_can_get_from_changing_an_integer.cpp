class Solution {
public:
    int maxDiff(int num) {
        vector<int> digits;
        while(num!=0) {
            digits.push_back(num%10);
            num/=10;
        }
        int maxVal=0, minVal=0;
        int maxKey=-1, minKey=-1;
        int size=digits.size();
        bool flag=false;
        if(digits[size-1]>1) {
            minKey=digits[size-1];
            flag=true;
        }
        if(digits[size-1]<9) {
            maxKey=digits[size-1];
        }
        for(int i=size-1; i>=0; i--) {
            if(digits[i]<9 && maxKey==-1) {
                maxKey=digits[i];
            }
            if(digits[i]==maxKey) {
                maxVal=(maxVal*10+9);
            } else {
                maxVal=(maxVal*10+digits[i]);
            }
            if(digits[i]>1 && minKey==-1) {
                minKey=digits[i];
            }
            if(digits[i]==minKey) {
                minVal=(minVal*10);
                if(flag) {
                    minVal++;
                }
            } else {
                minVal=(minVal*10+digits[i]);
            }
        }
        return maxVal-minVal;
    }
};
