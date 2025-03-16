class Solution {
public:
    int cutRod(vector<int> &price) {
        
        int n = price.size();
        
        //row and column sizes. look closely.
        int t[n+1][n+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(i > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = max(t[i-1][j], price[i-1] + t[i][j-i]);
                
            }
        }
        
        return t[n][n];
    }
};