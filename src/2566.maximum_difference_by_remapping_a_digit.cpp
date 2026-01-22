class Solution {
public:
    void getDigit(int n, vector<int>& remap, int count) {
        if(n==0) {
            return;
        }
        getDigit(n/10, digits);
    }
    int minMaxDifference(int num) {
        vector<int> remap(10, 0);
        vector<int> digits;
        int maxVal, minVal;
        getDigit(num, digits);

        return 0;
    }
};
