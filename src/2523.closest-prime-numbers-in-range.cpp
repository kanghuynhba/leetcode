/*
 * @lc app=leetcode id=2523 lang=cpp
 *
 * [2523] Closest Prime Numbers in Range
 */

// @lc code=start
class Solution {
public:
    vector<bool> selve(int upperLimit) {
        vector<bool> numb(upperLimit, true);
        numb[0]=false;
        numb[1]=false;
        for(int i=2; i*i<upperLimit; i++) {
            if(numb[i]) {
                for(int j=i*i; j<upperLimit; j+=i) {
                    numb[j]=false;
                }
            }
        }
        return numb;
    }
    vector<int> closestPrimes(int left, int right) {
        int minDiff=INT_MAX;
        int prime=-1, minPrime=-1;
        vector<bool> checkPrime=selve(right+1);
        for(int i=left; i<=right; i++) {
            if(checkPrime[i]) {
                if(prime!=-1 && minDiff>i-prime) {
                    minDiff=i-prime;
                    minPrime=prime;
                }
                prime=i;
            }
        }
        if(minPrime==-1) {
            return {-1, -1};
        }
        return {minPrime, minPrime+minDiff};
    }
};
// @lc code=end

