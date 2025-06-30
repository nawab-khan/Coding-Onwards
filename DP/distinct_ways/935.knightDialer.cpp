class Solution {
public:
    int mod = 1e9 + 7;

    int t[5001][10];

    int helper(int n, int lastPos, vector<vector<int>>& moves){
        
        if(n == 0)
            return 1;

        if(moves[lastPos].size() == 0)
            return 0;

        if(t[n][lastPos] != -1)
            return t[n][lastPos];

        int ans = 0;

        for(int i=0;i<moves[lastPos].size();i++){

            ans = (ans + helper(n-1, moves[lastPos][i], moves)%mod)%mod;

        }

        return t[n][lastPos] = ans;
    }

    int knightDialer(int n) {
        
        int res = 0;

        memset(t, -1, sizeof(t));

        vector<vector<int>> moves = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};

        // moves.push_back()

        for(int i=0;i<10;i++){

            res = (res + helper(n - 1, i, moves)%mod)%mod;

        }

        return res;

    }
};