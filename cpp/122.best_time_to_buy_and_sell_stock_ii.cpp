class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int initVal=prices[0];
        int ans=0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i-1]>prices[i]) {
                ans+=(prices[i-1]-initVal);
                initVal=prices[i];
            } else {
                ans+=prices[i]-initVal;
                initVal=prices[i];
            }
        }        
        return ans;
    }
};
