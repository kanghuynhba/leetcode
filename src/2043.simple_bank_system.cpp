class Bank {
    int n;
    vector<long long> bank;
public:
    Bank(vector<long long>& balance) {
        n=balance.size(); 
        for(int i=0; i<n; i++) {
            bank.push_back(balance[i]);
        }
    }

    bool isValid(int acc) {
        return acc>0 && acc<=n;
    } 
    
    bool transfer(int account1, int account2, long long money) {
        if(!withdraw(account1, money)) {
            return false;
        }
        if(!deposit(account2, money)) {
            deposit(account1, money);
            return false;
        }
        return true;
    }

    bool deposit(int account, long long money) {
        if(!isValid(account)) {
            return false;
        }    
        bank[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValid(account)) {
            return false;
        } 
        if(bank[account-1]-money<0) {
            return false;
        }
        bank[account-1]-=money;
        return true;

    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
