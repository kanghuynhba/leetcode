class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        for(int num : nums) {
            sum+=num;
        }       
        if(sum%3==0) {
            return sum;
        }
        int remainder=sum%3;
        sort(nums.begin(), nums.end());
        int minNum=INT_MAX;
        int num1=INT_MAX, num2=INT_MAX;
        bool flag=false;
        for(int num : nums) {
            if(num%3==remainder) {
                minNum=min(minNum, num);
                if(flag) {
                    return sum-minNum;
                }
            } else if(num%3!=0) {
                num2=min(num2, num1);
                num1=num;
                if(num2!=INT_MAX) {
                    minNum=min(minNum, num1+num2);
                    flag=true;
                }
           }
        }
        return sum-minNum;
    }
};
