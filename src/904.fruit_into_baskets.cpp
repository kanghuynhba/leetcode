class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first=-1, second=-1, ans=0;
        int fruit_1=0, fruit_2=0;
        for(int i=fruits.size()-1; i>=0; i--) {
            if(fruits[i]!=first && fruits[i]!=second) {
                second=first;
                first=fruits[i];
                fruit_2=fruit_1;
                fruit_1=1;
            } else {
                if(fruits[i]==first) {
                    fruit_1++;
                } else if(fruits[i]==second) {
                    swap(first, second);
                    fruit_2++;
                    swap(fruit_2, fruit_1);
                }
            }
            cout << first << " " << second << " " << fruit_1+fruit_2 << endl;
            ans=max(ans, fruit_1+fruit_2);
        }
        return ans;
    }
};
/* [1,2,1] */
/* [0,1,2,2] */
/* [1,2,2,3,3,1] */
/* [1,2,3,1,2,2] */
/* [1,2,3,2,2] */
/* [1,1,1,1,1,1] */
/* [3,3,3,1,2,1,1,2,3,3,4] */
/* [1,0,1,4,1,4,1,2,3] */

