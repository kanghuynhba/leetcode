class Solution {
public:
    int toInt(string s) {
        bool flag=true;
        int ans=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]>='0' && s[i]<='9') {
                ans+=(s[i]-'0');
                ans*=10;
                flag=false;
            } else if(!flag) {
                break;
            }
        }
        return ans/10;
    }
    void mentionProcess(vector<int>& users, string mention) {
        int id;
        int lastId=0;
        for(int i=0; i<mention.size(); i++) {
            if(mention[i]==' ') {
                id=toInt(mention.substr(lastId, i-lastId)); 
                lastId=i+1;
                users[id]++;
            }
        }
        id=toInt(mention.substr(lastId, mention.size()-lastId)); 
        users[id]++;
    }
    bool isOnline(vector<int>& state, int timestamp) {
        int id=upper_bound(state.begin(), state.end(), timestamp)-state.begin()-1;
        if(id>=0 && state[id]+60>timestamp && timestamp>=state[id]) {
            return false;
        }
        return true;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        char message;
        int timestamp;
        vector<int> users(numberOfUsers, 0);
        vector<vector<int>> state(numberOfUsers);
        vector<int> usersId;
        for(int i=0; i<events.size(); i++) {
            if(events[i][0]=="OFFLINE") {
                timestamp=toInt(events[i][1]);
                state[toInt(events[i][2])].push_back(timestamp);
            }
        }
        for(int i=0; i<numberOfUsers; i++) {
            sort(state[i].begin(), state[i].end());
        }
        int totalCount=0;
        for(int i=0; i<events.size(); i++) {
            if(events[i][0]=="MESSAGE") {
                timestamp=toInt(events[i][1]);
                if(events[i][2]=="ALL") {
                    totalCount++; 
                } else if(events[i][2]=="HERE") {
                    for(int j=0; j<numberOfUsers; j++) {
                        if(isOnline(state[j], timestamp)) {
                            users[j]++;
                        }
                    }
                } else {
                    mentionProcess(users, events[i][2]);
                }
            }
        }
        for(int i=0; i<numberOfUsers; i++) {
            users[i]+=totalCount;
        }
        return users;
    }
};
