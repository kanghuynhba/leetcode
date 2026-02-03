class Solution {
public:
    string reverseWords(string s) {
        string word, f="";
        int j=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]!=' ') {
                j=i;
                break;
            }
        }
        s=s.substr(j, s.size()-j);
        int size=s.size();
        for(int i=size-1; i>=0; i--) {
            if(s[i]==' ') {
                if(word=="") {
                    continue;
                }
                reverse(word.begin(), word.end());
                f+=word;
                f+=" ";
                word="";
            } else {
                word+=s[i];
            }
        }
        reverse(word.begin(), word.end());
        f+=word;
        return f;
    }
};
