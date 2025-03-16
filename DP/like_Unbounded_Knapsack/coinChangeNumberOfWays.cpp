class Solution {
public:
    int count(vector<int>& coins, int sum) {
        
        int n = coins.size();
        
        int t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                
                if(j == 0){
                    t[i][j] = 1;
                    continue;
                }
                else if(i == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(coins[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i][j - coins[i-1]];  
                
            }
        }
        
        return t[n][sum];
    }
};
