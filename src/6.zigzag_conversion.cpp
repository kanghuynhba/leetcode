class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) {
            return s;
        } 
        string ans;
        int size=s.size();
        int dist=2*(numRows-1);
        int j, count;
        for(int i=0; i<numRows; i++) {
            j=i;
            count=1;
            while(j<size) {
                ans+=s[j];
                if(i!=0 && i!=numRows-1) {
                    if(count*dist-i<size) {
                        ans+=s[count*dist-i];
                    }
                }
                j+=dist;
                count++;
            }
        }
        return ans;
    }
};
