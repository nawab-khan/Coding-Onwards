class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        
        vector<vector<int>> t(n+1, vector<int>(capacity+1));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<capacity+1;j++){
                
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(wt[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = max(t[i-1][j], val[i-1] + t[i][j - wt[i-1]]);
                
            }
        }
        
        return t[n][capacity];
    }
};