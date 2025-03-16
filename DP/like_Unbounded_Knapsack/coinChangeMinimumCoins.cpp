class Solution {
public:
    int minCoins(vector<int> &coins, int sum) {
        
        int n = coins.size();
        
        int t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                
                if(j == 0){
                    t[i][j] = 0;
                    continue;
                }
                else if(i == 0){
                    t[i][j] = -1;
                    continue;
                }
                
                if(coins[i-1] > j)
                    t[i][j] = t[i-1][j];
                else{
                    
                    if(t[i-1][j] != -1 && t[i][j-coins[i-1]] != -1){
                        t[i][j] = min(t[i-1][j], t[i][j - coins[i-1]] + 1);
                    }
                    else if(t[i-1][j] == -1){
                        t[i][j] = (t[i][j-coins[i-1]] == -1) ? -1 : t[i][j-coins[i-1]] + 1;
                    }
                    else{
                        t[i][j] = t[i-1][j];
                    }
                    
                }
                
            }
        }
        
        return t[n][sum];
    }
};


//Verma's Code

// int minCoins(int coins[], int M, int V) 
//     { 
//         int t[M+1][V+1];
//         //initilization
//         // first row and column initialized
//         for(int i=0;i<M+1;i++)
//         {
//             for(int j=0;j<V+1;j++)
//             {
//                 if(j==0) t[i][j]=0;
//                 if(i==0) t[i][j]=INT_MAX-1;
//             }
//         }
        
//         //second row initilization
//        /* */
//        for(int i=1;i<2;i++)
//         {
//             for(int j=1;j<V+1;j++)
//             {
//                 if(j % coins[0]==0)
//                     t[i][j]=j/coins[0];
//                 else
//                     t[i][j]=INT_MAX-1;
//             }
//         }
//         //main code for other blocks
//         for(int i=2;i<M+1;i++)
//         {
//             for(int j=1;j<V+1;j++)
//             {
//                if(j>=coins[i-1])
//                 t[i][j]=min(t[i-1][j], 1+t[i][j-coins[i-1]]);
//                 else
//                 t[i][j]=t[i-1][j];
//             }
//         }
//         if(t[M][V]==INT_MAX-1)
//             return -1;
//         else return t[M][V];
//     }