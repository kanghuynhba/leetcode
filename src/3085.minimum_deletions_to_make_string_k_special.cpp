class Solution {
public:
    int dfs(vector<int>& arr, int& k, int i, int j) {
        if(i<j) {
            int diff=arr[j]-arr[i];
            if(diff>k) {
                return min(dfs(arr, k, i+1, j)+arr[i], dfs(arr, k, i, j-1)+(diff-k));
            }
        }
        return 0;
    }
    int minimumDeletions(string word, int k) {
        vector<int> count(26, 0), arr;
        for(int i=0; i<word.size(); i++) {
            count[word[i]-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(count[i]>0) {
                arr.push_back(count[i]);
            }
        }
        sort(arr.begin(), arr.end());
        return dfs(arr, k, 0, arr.size()-1);
    }
};
