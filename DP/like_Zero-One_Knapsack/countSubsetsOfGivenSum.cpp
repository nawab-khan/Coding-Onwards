class Solution {
public:

    int perfectSum(vector<int>& arr, int target) {
        
        int n = arr.size(), count = 0;
        
        int t[n + 1][target + 1];
        
        for(int i=0;i<n+1;i++){
            
            for(int j=0;j<target+1;j++){
                
                if(i == 0 && j == 0){
                    t[i][j] = 1;
                    continue;
                }
                else if(i == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(arr[i-1] > j)
                    t[i][j] = t[i-1][j];
                else{
                    t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
                }
                
            }
            
        }
                
        return t[n][target];
    }
};