class Solution {
public:
    struct option {
        bool operator()(const pair<long long, int>& a, const pair<long long, int>& b) {
            if(a.first == b.first) {
                return a.second > b.second; 
            }
            return a.first > b.first; 
        }
    };
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n, 0);        
        int mostMeetings = 0, mostId=0;
        unordered_map<int, int> end;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, option> finished;
        priority_queue<int, vector<int>, greater<int>> start, available;
        for(int i=0; i<meetings.size(); i++) {
            end[meetings[i][0]] = meetings[i][1];
            start.push(meetings[i][0]);
        }
        for(int i=0; i<n; i++) {
            available.push(i);
        }
        while(!start.empty()) {
            int startTop=start.top();
            start.pop();
            while(!finished.empty() && finished.top().first<=startTop) {
                available.push(finished.top().second);
                finished.pop();
            }
            if(!available.empty()) {
                finished.push({end[startTop], available.top()});
                count[available.top()]++;
                available.pop();
                continue;
            }
            pair<long long, int> finishedTop=finished.top();
            finished.pop();
            count[finishedTop.second]++;
            finished.push({end[startTop]+(finishedTop.first-startTop), finishedTop.second});
        }
        for(int i = 0; i < n; i++) {
            if(mostMeetings<count[i]) {
                mostMeetings=count[i];
                mostId=i;
            }
        }
        return mostId;
    }
};
