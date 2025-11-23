class Solution {
public:
    int gcd(int a, int b) {
        if(a<b) {
            swap(a, b);
        }
        if(a%b==0) {
            return b;
        }
        return gcd(b, a%b);
    }
    int findOne(vector<int>& nums, int size) {
        int count=0;
        for(int i=0; i<size; i++) {
            if(nums[i]==1) {
                count++;
            }
        }
        return count;
    }
    int minOperations(vector<int>& nums) {
        int size=nums.size();
        int count=findOne(nums, size);
        if(count!=0) {
            return size-count;
        }
        for(int i=size; i>=2; i--) {
            for(int j=1; j<i; j++) {
                nums[j-1]=gcd(nums[j-1], nums[j]);
            }
            count++;
            if(findOne(nums, i)!=0) {
                return count+size-1;
            }
        }
        return -1;        
    }
};
