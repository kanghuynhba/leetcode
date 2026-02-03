class Solution {
public:
    bool hasSameDigits(string s) {
        int size=s.size();
        int ch1, ch2;
        string temp;
        while(size!=2) {
            temp="";
            for(int i=1; i<size; i++) {
                ch1=s[i-1]-'0';
                ch2=s[i]-'0';
                temp+=('0'+(ch2+ch1)%10);
            }
            s=temp;
            size--;
        }         
        return s[0]==s[1];
    }
};
