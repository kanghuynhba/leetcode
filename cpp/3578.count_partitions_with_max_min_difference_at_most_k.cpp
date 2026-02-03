class Solution {
public:
    int curMin(priority_queue<pair<int, int>, 
            vector<pair<int, int>>, greater<std::pair<int, int>>>& minHeap, int id) {
        while(!minHeap.empty() && minHeap.top().second<id) {
            minHeap.pop();
        }
        return minHeap.top().first;
    }
    int curMax(priority_queue<pair<int, int>, 
            vector<pair<int, int>>>& maxHeap, int id) {
        
        while(!maxHeap.empty() && maxHeap.top().second<id) {
            maxHeap.pop();
        }
        return maxHeap.top().first; 
    }
    int countPartitions(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, greater<std::pair<int, int>>> minHeap;
        int size=nums.size();
        const int mod=1e9+7;
        vector<long long> dp(size+1);
        vector<long long> prefix(size+1);
        dp[0]=1;
        prefix[0]=1;
        int j=0, curPrefixJ=0;
        for(int i=0; i<nums.size(); i++) {
            minHeap.push({nums[i], i});
            maxHeap.push({nums[i], i});
            while(curMax(maxHeap, j)-curMin(minHeap, j)>k) {
                j++;     
            }
            if(j>0) {
                curPrefixJ=prefix[j-1];
            }
            dp[i+1]=(prefix[i]-curPrefixJ+mod)%mod;
            prefix[i+1]=(prefix[i]+dp[i+1])%mod;
        }
        return dp[size];
    }
};
