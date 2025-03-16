class Solution {
public:
    bool equalPartition(vector<int>& arr) {
                    
        int n = arr.size(), sum = 0;
    
        for(int i : arr){
            sum += i;
        }
        
        if(sum&1)
            return false;

        int target = sum/2;
        
        int t[n+1][target+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                
                if(j == 0){
                    t[i][j] = 1;
                    continue;
                }
                if(i == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(arr[i-1] > j){
                    t[i][j] = t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
                }
                
            }
        }

        
        return t[n][target];
        
    }
};