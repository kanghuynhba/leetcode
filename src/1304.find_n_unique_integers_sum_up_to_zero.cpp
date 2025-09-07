class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr;
        if(n%2==1) {
            for(int i=-(n/2); i<=n/2; i++) {
               arr.push_back(i); 
            }
        } else {
            for(int i=-(n/2); i<=n/2; i++) {
                if(i==0) {
                    continue;
                } 
                arr.push_back(i); 
            }
        }
               
        return arr;
    }
};
