class Solution {
public:
    void dfs(string& ans, string& target, vector<int>& count, int start, bool flag) {
        if(ans.size()==target.size()) {
            return;
        }
        int lastId=ans.size()-1;
        int k=0;
        if(lastId>=0 && ans[lastId]>target[lastId]) {
            flag=true;
        }
        if(!flag) {
            k=target[start]-'a';
        }
        for(int j=k; j<26; j++) {
            if(count[j]>0) {
                ans+='a'+j;
                count[j]--;
                dfs(ans, target, count, start+1, flag);
                if(ans.size()==target.size() && ans>target) {
                    return;
                }
                ans.pop_back();
                count[j]++;
            }                 
        }
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        int ch;
        for(int i=0; i<s.size(); i++) {
            ch=s[i]-'a';
            count[ch]++;
        }
        string ans="";
        bool flag=false;
        dfs(ans, target, count, 0, flag);        
        return ans;
    }
};
