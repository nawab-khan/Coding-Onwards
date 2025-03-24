int minimumTotal(vector<vector<int>>& triangle) {
        
    int n = triangle.size();
    int m = triangle[n-1].size();

    vector<vector<int>> t(n, vector<int> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){

        if(i == 0){
            t[i][j] = triangle[i][j];   continue;
        }

        if(i == 1){
            t[i][j] = t[0][0] + triangle[i][j]; continue;
        }

        t[i][j] = min(((j >= i) ? 10001 :t[i-1][j]), ((j < 1) ? 10001 : t[i-1][j-1])) + triangle[i][j];
        
        }
    }

    int res = INT_MAX;
    for(int i=0;i<triangle[n-1].size();i++)
        res = min(res, t[n-1][i]);

    return res;
}