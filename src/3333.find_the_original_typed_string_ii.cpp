class Solution {
public:
    int possibleStringCount(string word, int k) {
        int ans=1, count=0;
        int size=word.size();
        for(int i=1; i<size; i++) {
            if(word[i-1]==word[i]) {
                count++;
            } else {
                if(size-count<k) {
                    count=size-k;
                }
                ans+=count;
                count=0;
            }
            if(size-count<k) {
                    count=size-k;
            }
            ans+=count;
            count=0;
            return ans;
        }
    }
};
