class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num : nums) {
            count[num]++;
        }
        int sum=0;
        for(auto it=count.begin(); it!=count.end(); it++) {
            if(it->second%k==0) {
                sum+=it->first*it->second;
            }
        }
        return sum;
    }
};
