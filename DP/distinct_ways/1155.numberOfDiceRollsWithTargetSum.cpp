class Solution {
public:
    int mod = 1e9 + 7;
    int t[31][1001];

    int helper(int n, int& k, int target){

        //bc
        if(n == 0)
            return target == 0;

        if(t[n][target] != -1)
            return t[n][target];

        int ans = 0;

        for(int i=1;i<=min(k, target);i++)
            ans = (ans + helper(n-1, k, target - i))%mod;

        return t[n][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        memset(t, -1, sizeof(t));

        return helper(n, k, target);
    }
};