class Solution {
    const int mod=1e9+7;
public:
    long long factorial(long long n) {
        if(n==1) {
            return n;
        }
        return (n*factorial(n-1)+mod)%mod;
    }
    int countPermutations(vector<int>& complexity) {
        int base=complexity[0];
        for(int i=1; i<complexity.size(); i++) {
            if(complexity[i]<=base) {
                return 0;
            }
        } 
        return factorial(complexity.size()-1);
    }
};
