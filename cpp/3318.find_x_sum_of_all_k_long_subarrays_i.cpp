class Solution {
public:
    struct option {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second>b.second || (a.second==b.second && a.first>b.first);
        }
    };
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int, int> mp;
        set<pair<int, int>, option> xSum, rest;
        for(int i=0; i<k; i++) {
            mp[nums[i]]++; 
        }
        int xSize=x;
        int total=0;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            xSum.insert({it->first, it->second});
        }
        for(auto it=xSum.begin(); it!=xSum.end(); it++) {
            if(xSize>0) {
                total+=it->first*it->second;
                xSize--;
            } else {
                rest.insert({it->first, it->second});
            }
        }
        while(xSum.size()>x) {
            auto it=xSum.rbegin();
            xSum.erase({it->first, it->second});
        }
        int j;
        ans.push_back(total);
        for(int i=1; i+k-1<nums.size(); i++) {
            j=i+k-1; 
            if(xSum.find({nums[i-1], mp[nums[i-1]]})!=xSum.end()) {
                xSum.erase({nums[i-1], mp[nums[i-1]]});
                mp[nums[i-1]]-=1;
                if(mp[nums[i-1]]>0) {
                    xSum.insert({nums[i-1], mp[nums[i-1]]});
                }
                total-=nums[i-1];
            } else {
                rest.erase({nums[i-1], mp[nums[i-1]]});
                mp[nums[i-1]]-=1;
                if(mp[nums[i-1]]>0) {
                    rest.insert({nums[i-1], mp[nums[i-1]]});
                }
            }
            if(xSum.find({nums[j], mp[nums[j]]})!=xSum.end()) {
                xSum.erase({nums[j], mp[nums[j]]});
                mp[nums[j]]++;
                xSum.insert({nums[j], mp[nums[j]]});
                total+=nums[j];
            } else {
                if(rest.find({nums[j], mp[nums[j]]})!=rest.end()) {
                    rest.erase({nums[j], mp[nums[j]]});
                }
                mp[nums[j]]++;
                rest.insert({nums[j], mp[nums[j]]});
            }
            if(xSum.size()>x) {
                auto it=xSum.rbegin();
                total-=(it->first*it->second);
                rest.insert({it->first, it->second});
                xSum.erase({it->first, it->second});
            } else if(xSum.size()<x) {
                auto it=rest.begin(); 
                total+=(it->first*it->second);
                xSum.insert({it->first, it->second});
                rest.erase({it->first, it->second});
            } else {
                auto it1=xSum.rbegin();
                auto it2=rest.begin();
                if(it1->second<it2->second || 
                        (it1->second==it2->second && it1->first<it2->first)) {
                    total+=(it2->first*it2->second);
                    total-=(it1->first*it1->second);
                    xSum.insert({it2->first, it2->second});
                    rest.insert({it1->first, it1->second});
                    xSum.erase({it1->first, it1->second});
                    rest.erase({it2->first, it2->second});
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
};
