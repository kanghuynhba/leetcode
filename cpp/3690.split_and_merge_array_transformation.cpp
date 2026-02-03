class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans={0,0,1,2,3,3,4};
        int size=nums1.size();
        vector<int> first, sec;
        unordered_map<int, int> h;
        int count=1;
        for(int i=0; i<size; i++) {
            if(h.find(nums1[i])==h.end()) {
                h[nums1[i]]=count++;
            }     
            nums1[i]=h[nums1[i]];
        }
        for(int i=0; i<size; i++) {
            nums2[i]=h[nums2[i]];
        }
        for(int i=0; i<size; i++) {
            if(nums1[i]!=nums2[i]) {
                first.push_back(nums1[i]);
                sec.push_back(nums2[i]);
            }
        }        
        size=first.size(); 
        int maxSubarray=0;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(first[i]==sec[j]) {

                }
            }
        }
        return 0;
    }
};
