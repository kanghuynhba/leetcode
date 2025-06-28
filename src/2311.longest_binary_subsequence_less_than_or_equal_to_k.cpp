class Solution {
public:
    int longestSubsequence(string s, int k) {
        int size = s.size();
        int countZeros = 0, countOnes = 0;
        long long numb = 0;
        bool flag = true;
        for (int i = 0; i < size; ++i) {
            if (s[size-i-1] == '0') {
                countZeros++;
            } else {
                if( flag) {
                    numb += pow(2, i);
                    countOnes++;
                }
            }
            if (numb > k) {
                if(flag) {
                    countOnes--;
                }
                flag = false;
            }
            if(i>=31) {
                flag = false;
            }
        }
        return countZeros + countOnes;
    }
};
