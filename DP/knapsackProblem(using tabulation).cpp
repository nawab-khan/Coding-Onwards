class Solution {
public:
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int size = val.size();
        
        int t[size+1][W+1];
        
        for(int i=0;i<size+1;i++){
            for(int j=0;j<W+1;j++){
                
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(wt[i-1] > j)
                    t[i][j] = t[i-1][j];
                else{
                    t[i][j] = max(t[i-1][j], val[i-1] + t[i-1][j-wt[i-1]]);
                }

            }
        }
        
        return t[size][W];
    }
}