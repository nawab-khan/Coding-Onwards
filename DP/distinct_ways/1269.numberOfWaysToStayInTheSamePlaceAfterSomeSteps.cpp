class Solution {
public:
    int mod = 1e9 + 7;
    int t[501][501];

    int helper(int n, int& l, int lastPos){

        if(lastPos < 0 ||lastPos >= l)
            return 0;

        if(n == 0)
            return lastPos == 0;

        if(t[n][lastPos] != -1)
            return t[n][lastPos];

        unsigned int ans = 0;

        ans = (ans + helper(n-1, l, lastPos)%mod + helper(n-1, l, lastPos - 1)%mod + helper(n-1, l, lastPos + 1)%mod)%mod;

        return t[n][lastPos] = ans;
    }

    int numWays(int steps, int arrLen) {

        memset(t, -1, sizeof(t));

        return helper(steps, arrLen, 0);

    }
};