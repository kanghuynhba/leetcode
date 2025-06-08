class Solution {
    // O(n) time and space complexity
    // Using a stack to track the indices of characters and a vector to mark which characters to keep
    // When encountering a '*', we pop the last character from the stack and mark it as not to be included
    // Finally, we construct the result string based on the marked characters
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
