class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        unordered_map<int, unordered_map<long long, pair<int, int>>> map;
        vector<long long> preSum;
        preSum.push_back(capacity[0]);
        for(int i=1; i<capacity.size(); i++) {
            preSum.push_back(preSum[i-1]+capacity[i]);
        }
        int l, r;
        long long ans=0;
        string curHash, curVal;
        int size=capacity.size();
        int curCap;
        long long curSum;
        for(int i=0; i<size; i++) {
            curCap=capacity[i];
            curSum=preSum[i];
            if(map.find(curCap)!=map.end() && map[curCap].find(curSum-2*curCap)!=map[curCap].end()) {
                if(i-map[curCap][curSum-2*curCap].second==1) {
                    ans+=(map[curCap][curSum-2*curCap].first-1); 
                } else {
                    ans+=map[curCap][curSum-2*curCap].first;
                }
            }        
            if(map.find(curCap)==map.end() && map[curCap].find(curSum)!=map[curCap].end()) {
                map[curCap][curSum].first=1;
            } else {
                map[curCap][curSum].first++;
            }
            map[curCap][curSum].second=i;
        }
        return ans;
    }
};
