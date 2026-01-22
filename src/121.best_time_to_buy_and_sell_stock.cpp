class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int size=prices.size();
        vector<int> maxProfit(size);
        maxProfit[size-1]=prices[size-1];
        for(int i=size-2; i>=0; i--) {
            maxProfit[i]=max(maxProfit[i+1], prices[i]);
            ans=max(ans,maxProfit[i]-prices[i]); 
        }
        return ans;
    }
};
