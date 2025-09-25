class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size=nums.size();
        int ans=1;
        vector<bool> visited(size+1, false);
        for(int num : nums) {
            if(num<=size && num>=0) {
                visited[num]=true;
            }
        }
        while(ans<=size && visited[ans]) {
            ans++;
        }
        return ans;
    }
};
