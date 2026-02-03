class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int> start, end;
        int size=meetings.size();
        for(int i=0; i<size; i++) {
            start.push_back(meetings[i][0]);
            end.push_back(meetings[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count=0;
        if(start[0]>1) {
            count+=(start[0]-1);
        }
        for(int i=1; i<size; i++) {
            if(end[i-1]<start[i]) {
                count+=(start[i]-end[i-1]-1);
            }
        }
        count+=(days-end[size-1]);
        return count;
    }
};
