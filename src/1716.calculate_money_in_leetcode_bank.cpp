class Solution {
public:
    int totalMoney(int n) {
        int k=n/7, h=n%7;
        int ans=k*28+7*(((k-1)*k)/2)+((h+1)*h)/2+h*k;
        return ans;
    }
};
