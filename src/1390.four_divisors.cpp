class Solution {
public:
    int countDivisor(int num) {
        int count=0;
        int total=0;
        for(int i=2; i<=sqrt(num); i++) {
            if(num%i==0) {
                if(num/i==i) {
                    total+=num/i;
                    count++;
                } else {
                    total+=(num/i)+i;
                    count+=2;
                }
            } 
        }
        if(count==2) {
            return total+1+num;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=countDivisor(nums[i]);
        }
        return sum;
    }
};
