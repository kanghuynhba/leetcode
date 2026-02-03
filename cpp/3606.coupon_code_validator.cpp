class Solution {
public:
    bool isValid(string s) {
        for(int i=0; i<s.size(); i++) {
            if(!((s[i]>='0' && s[i]<='9') 
                        || (s[i]>='a' && s[i]<='z') 
                        || (s[i]>='A' && s[i]<='Z')
                        || s[i]=='_')) {
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int size=code.size();
        vector<vector<string>> bsnes(4);
        for(int i=0; i<size; i++) {
            if(isActive[i] && code[i]!="" && isValid(code[i])) {
                if(businessLine[i]=="electronics") {
                    bsnes[0].push_back(code[i]);
                } else if(businessLine[i]=="grocery") {
                    bsnes[1].push_back(code[i]);
                } else if(businessLine[i]=="pharmacy") {
                    bsnes[2].push_back(code[i]);
                } else if(businessLine[i]=="restaurant") {
                    bsnes[3].push_back(code[i]);
                }
            } 
        }        
        for(int i=0; i<4; i++) {
            sort(bsnes[i].begin(), bsnes[i].end());
        }
        vector<string> ans;
        for(int i=0; i<4; i++) {
            for(int j=0; j<bsnes[i].size(); j++) {
                ans.push_back(bsnes[i][j]);
            }
        }
        
        return ans;
    }
};
