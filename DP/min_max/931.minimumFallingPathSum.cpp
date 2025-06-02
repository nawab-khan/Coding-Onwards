int minFallingPathSum(vector<vector<int>>& matrix) {
        
    int n = matrix.size();

    vector<vector<int>> t(n, vector<int> (n, 0));

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){

            if(i == n-1){
                t[i][j] = matrix[i][j];
            }
            else{
                if(j == n-1){
                    t[i][j] = matrix[i][j] + min(t[i+1][j-1], t[i+1][j]);
                }
                else if(j == 0){
                    t[i][j] = matrix[i][j] + min(t[i+1][j], t[i+1][j+1]);
                }
                else{
                    t[i][j] = matrix[i][j] + min(t[i+1][j-1], min(t[i+1][j], t[i+1][j+1]));
                }
            }

        }
    }

    int res = INT_MAX;
    for(int i=0;i<n;i++){
        res = min(res, t[0][i]);
    }

    return res;
}