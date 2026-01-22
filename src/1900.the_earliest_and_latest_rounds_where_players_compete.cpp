class Solution {
private:
    int F[30][30][30], G[30][30][30];
public:
    pair<int, int> dp(int n, int f, int s) {
        if(F[n][f][s]) {
            return {F[n][f][s], G[n][f][s]};
        }
        if(f+s==n+1) {
            return {1, 1};
        }

        // F(n,f,s)=F(n,n+1-s,n+1-f);
        if(f+s>n+1) {
            tie(F[n][f][s], G[n][f][s])=dp(n, n+1-s, n+1-f);
            return {F[n][f][s], G[n][f][s]}; 
        }

        int earliest=INT_MAX, latest=INT_MIN;
        int n_half=(n+1)/2;
        if(s<=n_half) {
            // On the left or on the middle 
            for(int i=0; i<f; ++i) {
                for(int j=0; j<s-f; ++j) {
                    pair<int, int> res=dp(n_half, i+1, i+j+2);
                    earliest=min(earliest, res.first);
                    latest=max(latest, res.second);
                }
            }
        } else {
            // On the right
            // s'
            int s_prime=n+1-s;
            int mid=(n-2*s_prime+1)/2;
            for(int i=0; i<f; ++i) {
                for(int j=0; j<s_prime-f; ++j) {
                    pair<int, int> res=dp(n_half, i+1, i+j+mid+2);
                    earliest=min(earliest, res.first);
                    latest=max(latest, res.second);
                }
            }
        }
        return {earliest+1, latest+1};
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        memset(F, 0, sizeof(F));               
        memset(G, 0, sizeof(G));

        pair<int, int> res=dp(n, firstPlayer, secondPlayer);
        return {res.first, res.second};
    }
};
