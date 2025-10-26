class Bank {
private:
vector<long long> balance;
bool checkAccount(int account) {
    if(account < 1 || account > this->balance.size()) {
        return false;
    }
    return true;
}

bool checkBalance(int account, long long money) {
    int index = account - 1;
    if(this->balance[index] >= money) {
        return true;
    }
    return false;
}

public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!(checkAccount(account1) && checkAccount(account2))){
            return false;
        }
        if(!checkBalance(account1,money)) return false;

        this->balance[account1-1]-=money;
        this->balance[account2-1]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!checkAccount(account)) return false;
        this->balance[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!checkAccount(account)) return false;
        if(!checkBalance(account,money)) return false;
        this->balance[account-1]-=money;
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
