/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
public:
    int findSmallest(vector<vector<int>>& ids, vector<int>& count) {
        int sm=0;
        if(ids[sm][count[sm]]>ids[1][count[1]]) {
            sm=1;
        }
        if(ids[sm][count[sm]]>ids[2][count[2]]) {
            sm=2;
        }
        return sm;
    }
    int numberOfSubstrings(string s) {
        vector<vector<int>> ids(3);
        int size=s.size();
        for(int i=0; i<size; i++) {
            ids[s[i]-'a'].push_back(i);
        }
        for(int i=0; i<=2; i++) {
            if(ids[i].size()==0) {
                return 0;
            }
        }
        vector<int> count(3, 0);
        int sm=findSmallest(ids, count);
        int largest=max(ids[0][count[0]], max(ids[1][count[1]], ids[2][count[2]]));
        int sum=0;      
        while(true) {
            largest=max(ids[0][count[0]], max(ids[1][count[1]], ids[2][count[2]]));
            sum+=size-largest;
            count[sm]++;
            if(count[sm]==ids[sm].size()) {
                break;
            }
            sm=findSmallest(ids, count);
        }    
        return 
    }
};
// @lc code=end

