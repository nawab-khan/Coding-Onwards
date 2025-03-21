int t[13][10001];

int helper(vector<int>& coins, int amount, int n){
    
    if(n <= 0 || amount <= 0){
        return (amount == 0) ? 0 : INT_MAX - 1;
    }

    if(t[n][amount] != -1){
        return t[n][amount];
    }

    if(coins[n-1] > amount)
        return t[n][amount] = helper(coins, amount, n-1);

    return t[n][amount] = min(helper(coins, amount, n-1), 1 + helper(coins, amount - coins[n-1], n));
}

int coinChange(vector<int>& coins, int amount) {

    // sort(coins.begin(), coins.end());

    memset(t, -1, sizeof(t));

    int res = helper(coins, amount, coins.size());

    return res == INT_MAX-1 ? -1 : res;

}