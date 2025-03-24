int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
    int n = dungeon.size(), m = dungeon[0].size();

    vector<vector<int>> t(n+1, vector <int> (m+1, INT_MAX));

    t[n-1][m] = 1, t[n][m-1] = 1;

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){

            t[i][j] = min(t[i+1][j], t[i][j+1]) - dungeon[i][j];

            if(t[i][j] <= 0)
                t[i][j] = 1;
        }
    }

    return t[0][0];
    // return helper(dungeon, 0, 0);

}