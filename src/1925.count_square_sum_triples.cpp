class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(double i=1; i<n; i++) {
            for(double j=1; j<n; j++) {
                if(sqrt(i*i+j*j)-floor(sqrt(i*i+j*j))==0) {
                    count++;
                }
            }
        }
        return count;
    }
};
