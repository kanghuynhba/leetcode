/*
 * @lc app=leetcode id=2115 lang=cpp
 *
 * [2115] Find All Possible Recipes from Given Supplies
 */

// @lc code=start
class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& graph, string& recipe, unordered_map<string, int>& check, bool& flag) {
        if(graph.find(recipe)==graph.end()) {
            flag=false;
            return;
        }
        check[recipe]=1;
        for(int i=0; i<graph[recipe].size(); i++) {
            string preRecipe=graph[recipe][i];
            if(check.find(preRecipe)==check.end()) {
                dfs(graph, preRecipe, check, flag);
            } else if(check[preRecipe]==1) {
                flag=false;
                return;
            }
            if(!flag) {
                return;
            }
        }
        if(flag) {
            check[recipe]=2;
        }
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> check;
        vector<string> ans;
        for(int i=0; i<recipes.size(); i++) {
            for(int j=0; j<ingredients[i].size(); j++) {
                graph[recipes[i]].push_back(ingredients[i][j]);
            }
        }
        for(int i=0; i<supplies.size(); i++) {
            check[supplies[i]]=2;
        }
        for(int i=0; i<recipes.size(); i++) {
            bool flag=true;
            if(check.find(recipes[i])==check.end()) {
                dfs(graph, recipes[i], check, flag);
            }
            if(flag && check[recipes[i]]==2) {
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

