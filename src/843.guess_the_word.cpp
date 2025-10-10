/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    bool match(int same, string w1, string w2) {
        int count=0;
        for(int i=0; i<6; i++) {
            if(w1[i]==w2[i]) {
                count++;
            }
        }
        return count==same;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        int size, same, randNum;
        while(!words.empty()) {
            size=words.size();
            randNum=rand()%size; 
            same=master.guess(words[randNum]); 
            if(same==6) {
                return;
            }
            vector<string> picks;
            for(int i=0; i<size; i++) {
                if(match(same, words[i], words[randNum])) {
                    picks.push_back(words[i]);
                }
            }            
            words=picks;
        }
        return;
    }
};
