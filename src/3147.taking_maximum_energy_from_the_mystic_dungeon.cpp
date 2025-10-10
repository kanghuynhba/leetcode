class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=INT_MIN;
        int size=energy.size();
        for(int i=size-1; i>=0; i--) {
            if(i+k<size) {
                energy[i]+=energy[i+k];
            }
            ans=max(ans, energy[i]);
        }
        return ans;
    }
};
