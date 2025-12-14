class Solution {
public:
    int reverseBits(int numb) {
        int ans=0;
        while(numb>0) {
            ans=numb|1;
            cout << ans << endl;
            ans<<=1;
            numb>>=1;
        }
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        for(int num : nums) {
            cout << num << " " << reverseBits(num) << endl;
        }
        return nums;
    }
};
