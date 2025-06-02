int mod = 1e9 + 7;
int t[51][51][51];

int helper(int& m, int& n, int k, int i, int j){

    if(i < 0 || i >= m || j < 0 || j >= n){
        return 1;
    }

    if(k == 0)
        return 0;

    if(t[i][j][k] != -1)
        return t[i][j][k];

    int res = 0;

    res = (res + helper(m, n, k-1, i+1, j))%mod;
    res = (res + helper(m, n, k-1, i-1, j))%mod;
    res = (res + helper(m, n, k-1, i, j+1))%mod;
    res = (res + helper(m, n, k-1, i, j-1))%mod;

    return t[i][j][k] = res;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    
    memset(t, -1, sizeof(t));

    return helper(m, n, maxMove, startRow, startColumn);
}