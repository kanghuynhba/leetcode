class Solution {
public:
    struct option {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first<b.first || (a.first==b.first && a.second<b.second);
        }
    };
    pair<int, int> count(string s) {
        int m=0, n=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='0') {
                m++;
            } else {
                n++;
            }
        }
        return {m, n};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr;
        for(int i=0; i<strs.size(); i++) {
            arr.push_back(count(strs[i])); 
        }        
        sort(arr.begin(), arr.end(), option());
        int ans;
        for(int i=0; i<arr.size(); i++) {
            if(m<0 || n<0) {
                return i;
            } 
            ans=i;
            m-=arr[i].first;
            n-=arr[i].second;
        }
        if(m<0 || n<0) {
            return ans;
        }
        return arr.size();
    }
};
