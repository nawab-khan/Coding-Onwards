int maximalSquare(vector<vector<char>>& matrix) {

    int m = matrix.size(), n = matrix[0].size(), res = 0;

    vector<vector<int>> t (m, vector<int> (n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(i == 0 || j == 0){
                t[i][j] = matrix[i][j] - '0';
            }
            else if(matrix[i][j] == '0'){
                t[i][j] = 0;
            }
            else{
                t[i][j] = 1 + min(t[i-1][j-1], min(t[i-1][j], t[i][j-1]));
            }

            res = max(res, t[i][j]);

        }
    }
    return res*res;
}