class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod=1e9+7;
        queue<pair<int, int>> know, share;
        know.push({1,1});
        int know_cnt=1, share_cnt=0;
        for(int i=2; i<=n; i++) {
            if(!know.empty() && know.front().first==i-delay) {
                know_cnt=(know_cnt-know.front().second+mod)%mod;
                share_cnt=(share_cnt+know.front().second)%mod;
                share.push(know.front());
                know.pop();
            }
            if(!share.empty() && share.front().first==i-forget) {
                share_cnt=(share_cnt-share.front().second+mod)%mod;
                share.pop();
            }
            if(!share.empty()) {
                know_cnt=(know_cnt+share_cnt)%mod;
                know.push({i, share_cnt});
            }
        }
        return (know_cnt+share_cnt)%mod;
    }
};
