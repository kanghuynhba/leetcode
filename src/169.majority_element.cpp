class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int ,int> count;
        int majority=(int)nums.size()/2;
        for(int i=0; i<nums.size(); i++) {
            if(count.find(nums[i])==count.end()) {
                count[nums[i]]=1;
            } else {
                count[nums[i]]++;
            }
            if(count[nums[i]]>majority) {
                return nums[i];
            }
        }
        return -1;
    }
};
