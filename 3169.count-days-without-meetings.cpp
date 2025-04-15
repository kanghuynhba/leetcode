/*
 * @lc app=leetcode id=3169 lang=cpp
 *
 * [3169] Count Days Without Meetings
 */

// @lc code=start
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int> start, end;
        for(int i=0; i<meetings.size(); i++) {
            start.push_back(meetings[i][0]);
            end.push_back(meetings[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i=0, j=0;
        int startSize=start.size(), endSize=end.size();
        while(i<startSize && j<endSize) {
            int count=0;
            if(start[i]<end[j]) {
                days-=(end[j]-start[i]+1);
                while(i<startSize && start[i]<end[j]) {
                    count++;
                }
            } else {
                j++;
            }
        }
        return days;
    }
};
// @lc code=end

