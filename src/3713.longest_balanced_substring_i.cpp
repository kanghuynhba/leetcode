class Solution {
public:
    int longestBalanced(string s) {
    int size=s.size();
    int curCount=0, maxCount=0;
    int check;
    bool flag;
    for(int i=0; i<size; i++) {
        vector<int> count(26, 0);
        for(int j=i; j<size; j++) {
            curCount=0;
            flag=true;
            check=++count[s[j]-'a'];
            for(int k=0; k<26; k++) {
                if(count[k]==0) {
                    continue;
                }
                if(count[k]==check) {
                    curCount+=count[k]; 
                } else {
                    flag=false;
                    break;
                }
            }
            if(flag) {
                maxCount=max(maxCount, curCount);
            }
        }
    }
    return maxCount;
}
};
