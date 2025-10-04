class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int size=rains.size();
        vector<int> ans(size, 1);        
        set<int> zeros;
        unordered_map<int, int> intervals;
        int begin;
        for(int i=0; i<size; i++) {
            if(rains[i]==0) {
                zeros.insert(i);
            } else {
                ans[i]=-1;
                if(intervals.count(rains[i])) {
                    begin=intervals[rains[i]];
                    auto id=zeros.lower_bound(begin);
                    if(id==zeros.end()) {
                        return {};
                    }
                    ans[*id]=rains[i];
                    zeros.erase(*id);
                }
                
                intervals[rains[i]]=i;
            }
        }
        return ans;
    }
};
