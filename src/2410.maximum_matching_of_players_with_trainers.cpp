class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), greater<int>());      
        sort(trainers.begin(), trainers.end(), greater<int>());
        int ans=players.size();
        int i=0, j=0;
        cout << players[i] << endl;
        return ans;
    }
};
