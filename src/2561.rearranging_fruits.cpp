class Solution {
public:
    unordered_map<int, int> countBasket(vector<int>& basket, unordered_map<int, int>& otherCount) {
        unordered_map<int, int> count;
        for(int i=0; i<basket.size(); i++) {
            if(otherCount.find(basket[i])==otherCount.end()) {
                otherCount[basket[i]]=0;
            }
            if(count.find(basket[i])==count.end()) {
                count[basket[i]]=1;
            } else {
                count[basket[i]]++;
            }
        }
        return count;
    }
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        sort(basket1.begin(), basket1.end());       
        sort(basket2.begin(), basket2.end());       
        unordered_map<int, int> count1, count2;
        count1=countBasket(basket1, count2);   
        count2=countBasket(basket2, count1);   
        int size=basket1.size();
        int i=0, j=size-1;
        long long ans=0;
        while(i<size && j>=0) {
            int ele1=basket1[i], ele2=basket2[j];
            if(count1[ele1]+count2[ele1]%2==1) {
                return -1;
            }
            if(count1[ele2]+count2[ele2]%2==1) {
                return -1;
            }
            while(count1[ele1]==count2[ele1]) {
                i++;
                if(i==size) {
                    break;
                }
                ele1=basket1[i];
            }
            while(count1[ele2]==count2[ele2]) {
                j--;
                if(j==-1) {
                    break;
                }
                ele2=basket2[j];
            }
            cout << i << " " << ele1 << " " << j << " " << ele2 << endl;
            if(ele1!=ele2) {
                count1[ele1]--;
                count2[ele1]++;
                count1[ele2]++;
                count2[ele2]--;
                ans+=min(ele1, ele2);
            }
            i++, j--;
        }
        return ans;
    }
};
