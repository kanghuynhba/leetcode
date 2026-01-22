class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());        
        long long div;
        int id;
        vector<int> ans;
        int size=potions.size();
        for(int i=0; i<spells.size(); i++) {
            div=success/spells[i];
            if(success%spells[i]>0) {
                div++;
            }
            id=lower_bound(potions.begin(), potions.end(), div)-potions.begin()-1;
            if(id==size) {
                ans.push_back(0);
            } else {
                ans.push_back(size-id-1);
            }
        }
        return ans;
    }
};
