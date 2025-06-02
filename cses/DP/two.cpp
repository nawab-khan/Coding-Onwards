#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

int t[1000001];

int helper(int target, vector<int>& coins, int& n){

    if(target == 0)
        return 0;

    if(t[target] != -1)
        return t[target];

    int ans = INT_MAX - 1;

    for(int i=0;i<n;i++){
        if(target >= coins[i])
            ans = min(1 + helper(target - coins[i], coins, n), ans);
    }
    
    return t[target] = ans;
}

int main(){
    
    memset(t, -1, sizeof(t));

    int n, x;
    cin >> n >> x;

    vector<int> coins (n, 0);

    for(int i=0;i<n;i++)
        cin >> coins[i];
    
    int res = helper(x, coins, n);

    if(res > x)
        cout << -1;
    else
        cout << res;
}