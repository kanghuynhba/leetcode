class Solution {
public:
    int lower_bound(vector<pair<int, int>>& arr, int left, int right, int x) {
        int pos=right;
        while(left<right) {
            int mid=left+(right-left)/2;
            if(arr[mid].first<x) {
                left=mid+1;
            } else {
                pos=mid;
                right=mid;
            }
        }
        return pos;
    }
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<pair<int, int>> blank;
        int size=startTime.size();
        if(startTime[0]>0) {
            blank.push_back({startTime[0], 0});
        }
        for(int i=1; i<size; i++) {
            if(startTime[i]-endTime[i-1]>0) {
                blank.push_back({startTime[i]-endTime[i-1], endTime[i-1]});
            }
            if(i==size-1 && endTime[i]<eventTime) {
                blank.push_back({eventTime-endTime[i], endTime[i]});
            }
        }       
        sort(blank.begin(), blank.end());
        int blankSize=blank.size();
        int ans=0;
        for(int i=0; i<size; i++) {
            int curBlank=endTime[i]-startTime[i];
            int fillId=lower_bound(blank, 0, blankSize-1, curBlank);
            int prevEnd=0;
            if(i>0) {
                prevEnd=endTime[i-1];
            }
            while(fillId>=0 && (blank[fillId].second==prevEnd || blank[fillId].second==endTime[i] || blank[fillId].first<curBlank)) {
                fillId++;
                if(fillId>=blankSize) {
                    break;
                }
            }
            if(fillId<blankSize && fillId>=0) {
                if(i<size-1) {
                    ans=max(ans, startTime[i+1]-prevEnd);
                } else {
                    ans=max(ans, eventTime-prevEnd);
                }
            }
            if(i<size-1) {
                ans=max(ans, startTime[i+1]-prevEnd-curBlank);
            } else {
                ans=max(ans, eventTime-prevEnd-curBlank);
            }
       }
        return ans;
    }
};
