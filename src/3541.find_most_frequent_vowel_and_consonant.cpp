class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> count(26, 0);        
        int maxVow=0, maxCon=0;
        for(int i=0; i<s.size(); i++) {
            count[s[i]-'a']++;
            if(s[i]=='a' || s[i]=='i'
                    || s[i]=='e' || s[i]=='o' || s[i]=='u') {
                maxVow=max(maxVow, count[s[i]-'a']);
            } else {
                maxCon=max(maxCon, count[s[i]-'a']);
            }
        }
        return maxVow+maxCon;
    }
};
