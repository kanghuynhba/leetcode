class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> count(26);
        vector<bool> check(s.size(), true);
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='*') {
                for(int i=0; i<26; i++) {
                    if(!count[i].empty()) {
                        check[count[i].top()]=false;
                        count[i].pop();
                        break;
                    }
                }
            } else {
                count[s[i]-'a'].push(i);
            }
        }
        string ans="";
        for(int i=0; i<s.size(); i++) {
            if(s[i]!='*' && check[i]) {
                ans+=s[i];
            }
        }
        return ans;
    }
};
