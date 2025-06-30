class Solution {
public:
    int mod = 1e9 + 7;
    int t[20001][5];

    int helper(int n, int lastPos, vector<vector<int>>& next){

        if(n == 0)
            return 1;

        if(t[n][lastPos] != -1)
            return t[n][lastPos];

        int ans = 0;

        for(int i=0;i<next[lastPos].size();i++){

            ans = (ans + helper(n-1, next[lastPos][i], next)%mod)%mod;

        }

        return t[n][lastPos] = ans;

    }

    int countVowelPermutation(int n) {
        
        memset(t, -1, sizeof(t));

        vector<vector<int>> next = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};

        int res = 0;

        for(int i=0;i<5;i++){

            res = (res + helper(n-1, i, next)%mod)%mod;

        }

        return res;

    }
};