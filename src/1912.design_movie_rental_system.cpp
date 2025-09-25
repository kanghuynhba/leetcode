class MovieRentingSystem {
private:
    struct option{
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first>b.first || (a.first==b.first && a.second>b.second); 
        }
    };
    struct option1{
        bool operator() (const vector<int>& a,const vector<int>& b) const {
            if(a[0]!=b[0]) {
                return a[0]>b[0];
            }
            if(a[1]!=b[1]) {
                return a[1]>b[1];
            }
            return a[2]>b[2];
        }
    };
    // dp[movie][shop]
    unordered_map<int, unordered_map<int, pair<int, bool>>> dp;
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, option>> unrented;
    priority_queue<vector<int>, vector<vector<int>>, option1> rented;
    bool contain(int key) {
        return unrented.find(key)!=unrented.end(); 
    }
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        int shop, movie, price;
        for(int i=0; i<entries.size(); i++) {
            shop=entries[i][0];
            movie=entries[i][1];
            price=entries[i][2];
            // true -> unrented
            // false -> rented
            dp[movie][shop]={price, true};
        }           
    }
    
    vector<int> search(int movie) {
        int shop, price;
        pair<int, int> state;
        vector<int> ans;
        // check whether contains minHeap for movie or not
        if(!contain(movie) || unrented[movie].empty()) {
            for(auto it=dp[movie].begin(); it!=dp[movie].end(); it++) {
                shop=it->first;
                state=it->second;
                if(state.second) {
                    unrented[movie].push({state.first, shop});
                }
            }
        }
        int top=5;
        // get top 5 cheapest elements from minHeap
        while(top>0 && !unrented[movie].empty()) {
            price=unrented[movie].top().first;
            shop=unrented[movie].top().second;
            unrented[movie].pop();
            ans.push_back(shop);
            top--;
        }
        for(int i=0; i<ans.size(); i++) {
            int shop=ans[i];
            int price=dp[movie][shop].first;
            unrented[movie].push({price, shop});
        }
        return ans; 
    }
    
    void rent(int shop, int movie) {
        dp[movie][shop].second=false;
        int price=dp[movie][shop].first;
        rented.push({price, shop, movie});
        vector<pair<int, int>> temp;
        while(contain(movie) && !unrented[movie].empty()) {
            int curPrice=unrented[movie].top().first;
            int curShop=unrented[movie].top().second;
            unrented[movie].pop();
            if(curShop==shop) {
                break;
            }
            temp.push_back({curPrice, curShop});
        }
        for(int i=0; i<temp.size(); i++) {
            unrented[movie].push(temp[i]);
        }
    }
    
    void drop(int shop, int movie) {
        dp[movie][shop].second=true;
        int price=dp[movie][shop].first;
        if(contain(movie)) {
            unrented[movie].push({price, shop});
        }
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int shop, price, movie;
        int top=5;
        while(top>0 && !rented.empty()) {
            price=rented.top()[0]; 
            shop=rented.top()[1]; 
            movie=rented.top()[2]; 
            rented.pop();
            if(!dp[movie][shop].second) {
                int lastId=ans.size()-1;
                if(lastId>=0 && !(shop==ans[lastId][0] && movie==ans[lastId][1])) {
                    ans.push_back({shop, movie});
                    top--;
                } else if(lastId<0) {
                    ans.push_back({shop, movie});
                    top--;
                }
            }         
        }
        for(int i=0; i<ans.size(); i++) {
            shop=ans[i][0];
            movie=ans[i][1];
            price=dp[movie][shop].first;
            rented.push({price, shop, movie});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
