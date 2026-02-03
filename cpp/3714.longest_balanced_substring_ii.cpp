class Solution {
public:
    string itoa(int numb) {
        if(numb==0) {
            return "";
        }
        string s="";
        if(numb<0) {
            s+="-";
        }
        s+='0'+numb%10;
        return itoa(numb/10)+s;
    }
    int maxChar(string& s, char c) {
        int maxCount=0, count=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==c) {
                count++;
            } else {
                count=0;
            }
            maxCount=max(maxCount, count);
        }
        return maxCount;
    }
    int maxChar(string& s, char c1, char c2) {
        unordered_map<int, int> check;
        int maxCount=0;
        int countC1=0, countC2=0;
        int hash, minNum=INT_MAX;
        for(int i=0; i<s.size(); i++) {
            if(s[i]!=c1 && s[i]!=c2) {
                countC1=0;
                countC2=0;
                check.clear();
            } else {
                if(s[i]==c1) {
                    countC1++;
                } else {
                    countC2++;
                }
                if(countC1==countC2) {
                    maxCount=max(maxCount, countC1*2);
                } else {
                    hash=countC1-countC2;
                    minNum=min(countC1, countC2);
                    if(check.find(hash)!=check.end()) {
                        maxCount=max(maxCount, (minNum-check[hash])*2);
                    } else {
                        check[hash]=minNum;
                    }
                }
            }
        }
        return maxCount;
    }
    int maxChar(string& s, char c1, char c2, char c3) {
        unordered_map<string, int> check;
        int maxCount=0;
        int minNum=INT_MAX;
        int countC1=0, countC2=0, countC3=0;
        string hash="";
        for(int i=0; i<s.size(); i++) {
            if(s[i]==c1) {
                countC1++;
            } else if(s[i]==c2) {
                countC2++;
            } else {
                countC3++;
            }
            if(countC1==countC2 && countC2==countC3) {
                maxCount=max(maxCount, countC1*3);
            } else {
                hash=itoa(countC1-countC2)+","+itoa(countC2-countC3);
                minNum=min(countC1, min(countC2, countC3));
                if(check.find(hash)!=check.end()) {
                    maxCount=max(maxCount, (minNum-check[hash])*3);
                } else {
                    check[hash]=minNum;
                }
            }
        }
        return maxCount;
    }
    int longestBalanced(string s) {
        unordered_set<string> check;
        int ch, a=0, b=0, c=0;
        int maxCount=0;
        maxCount=max(maxCount, maxChar(s, 'a'));
        maxCount=max(maxCount, maxChar(s, 'b'));
        maxCount=max(maxCount, maxChar(s, 'c'));
        maxCount=max(maxCount, maxChar(s, 'a', 'b')); 
        maxCount=max(maxCount, maxChar(s, 'b', 'c')); 
        maxCount=max(maxCount, maxChar(s, 'a', 'c')); 
        maxCount=max(maxCount, maxChar(s, 'a', 'b', 'c')); 
        cout << "3: " << maxCount << endl;
        return maxCount;
    }
};
/* "abbac" */
/* "abbbcaabaabcccbaabcbabaabacbabababacbacbabcabcab" */
/* "cbbbab" */
/* "aabcc" */
/* "aba" */
/* "cbabccbccb" */
