class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;

        vector<vector<int>> t (m, vector<int> (n, 0));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0)
                    t[i][j] = 1;
                else if(j == 0)
                    t[i][j] = (grid[i][j] == 0) && t[i-1][j];
                else if(i == 0)
                    t[i][j] = (grid[i][j] == 0) && t[i][j-1];
            }

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){

                if(grid[i][j])
                    t[i][j] = 0;
                else
                    t[i][j] = t[i-1][j] + t[i][j-1];

            }

        return t[m-1][n-1];
    }
};