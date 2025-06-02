int t[200][200];

int helper(int i, int j, vector<vector<int>>& grid){

    int n = grid.size() - 1;
    int m = grid[0].size() - 1;

    if(i == n && j == m)
        return grid[n][m];

    if(t[i][j] != -1)
        return t[i][j];

    int right = INT_MAX, down = INT_MAX;

    if(j < m)
        right = grid[i][j] + helper(i, j+1, grid);

    if(i < n)
        down = grid[i][j] + helper(i+1, j, grid);

    return t[i][j] = min(right, down);
}

int minPathSum(vector<vector<int>>& grid) {

    memset(t, -1, sizeof(t));

    return helper(0, 0, grid);
}