class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) {
           return word;
        }
        
int maxId=0;
        int curCh=0;
        for(int i=0; i<word.size(); i++) {
            if(curCh<word[i]-'a') {
                clurCh=word[i]-'a';
                maxId=i;
            }
        }
        if(numFriends-1-maxId>0) {
            return word.substr(maxId, word.size()-numFriends+1);
        }
        return word.substr(maxId, word.size()-maxId);
    }
};
