/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, int>& count, int level) {
        if(root==NULL) {
            return;
        }
        dfs(root->left, count, level+1);
        count[level]+=root->val;
        dfs(root->right, count, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN, ans=INT_MAX;
        unordered_map<int, int> count;
        dfs(root, count, 1);
        for(auto it=count.begin(); it!=count.end(); it++) {
            if(maxSum<it->second) {
                maxSum=it->second;
                ans=it->first;
            } else if(maxSum==it->second) {
                ans=min(ans, it->first);
            }
        }
        return ans;
    }
};
