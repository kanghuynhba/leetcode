class Solution {
public:
    int maxDifference(string s) {
        vector<int> count(26, 0);
        for(int i=0; i<s.size(); i++) {
            count[s[i]-'a']++;
        }
        int maxOdd=1, minEven=1000;
        for(int i=0; i<26; i++) {
            if(count[i]!=0 && count[i]%2==0) {
                minEven=min(minEven, count[i]);
            } else if(count[i]%2==1) {
                maxOdd=max(maxOdd, count[i]);
            } 
        }
        return maxOdd-minEven;
    }
};
