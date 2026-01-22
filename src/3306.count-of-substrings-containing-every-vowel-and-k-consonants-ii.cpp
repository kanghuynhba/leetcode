/*
 * @lc app=leetcode id=3306 lang=cpp
 *
 * [3306] Count of Substrings Containing Every Vowel and K Consonants II
 */

// @lc code=start
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int i=0, j=0;
        int countVowel=0, countConsonant=0;
        long long ans=0;
        vector<int> count(26, 0);
        string vowels="aeiou";
        while(j<i && i<word.size()) {
            countVowel=0;
            countConsonant=0;
            count[word[i]-'a']++;
            for(int k=0; k<26; k++) {
                for(int h=0; h<vowels.size(); h++) {
                    if(word[k]==vowels[h]) {
                        if(count[word[k]-'a']>0) {
                            countVowel++;
                        }
                    } else if(count[word[k]-'a']>0){
                        countConsonant++;
                    }
                }
            }
            if(countConsonant==k && countVowel==5) {
                ans++;
                count[word[j]-'a']--;
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end

