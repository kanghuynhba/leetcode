class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int j=1, i=0;
        int ans=0;
        int size=colors.size();
        while(i<size && j<size) {
            if(colors[i]==colors[j]) {
                ans+=min(neededTime[i], neededTime[j]);            
                neededTime[i]=max(neededTime[i], neededTime[j]);            
                neededTime[j]=max(neededTime[i], neededTime[j]);            
            } else {
                i=j;
            }
            j++;
        } 
        return ans;
    }
};
