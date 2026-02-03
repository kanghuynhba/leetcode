
class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> st;
        for(int i=0; i<s.size(); i++) {
            if(!st.empty() && st[st.size()-1].first==s[i]) {
                st[st.size()-1].second++;
            } else {
                st.push_back({s[i], 1}); 
            }
            int size=st.size();
            if(size>=2 && st[size-2].first=='(' && st[size-1].first==')' 
                    && st[size-2].second>=k && st[size-1].second==k) {
                st[size-2].second-=k;
                st.pop_back();
                if(st[st.size()-1].second==0) {
                    st.pop_back();
                }
            }
        }
        string ans="";
        for(int i=0; i<st.size(); i++) {
            while(st[i].second>0) {
                ans+=st[i].first;
                st[i].second--;
            }
        }
        return ans;
    }
};



