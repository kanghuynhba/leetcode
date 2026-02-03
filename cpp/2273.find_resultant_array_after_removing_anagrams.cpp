class Solution {
public:
    bool isAnagrams(string s1, string s2) {
        if(s1.size()!=s2.size()) {
            return false;
        }
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for(int i=0; i<s1.size(); i++) {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(count1[i]!=count2[i]) {
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1; i<words.size(); i++) {
            if(!isAnagrams(words[i-1], words[i])) {
                ans.push_back(words[i]);
            }
        } 
        return ans;
    }
};
