class Bank {
private:
    vector<long long> accounts;
    int n;

public:
    Bank(vector<long long>& balance) {
        accounts = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 || account1 > n || account2 < 1 || account2 > n) {
            return false;
        }
        
        if (accounts[account1 - 1] < money) {
            return false;
        }
    
        accounts[account1 - 1] -= money;
        accounts[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 || account > n) {
            return false;
        }
        
        accounts[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 || account > n) {
            return false;
        }
        
        if (accounts[account - 1] < money) {
            return false;
        }
        
        accounts[account - 1] -= money;
        return true;
    }
};