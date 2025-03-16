class Solution {
public:
    int minDifference(vector<int>& arr) {
        
        int n = arr.size(), sum = 0, s = 0;
        
        for(int i : arr){
            sum += i;
        }
        
        bool t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            
            for(int j=0;j<sum+1;j++){
                
                if(j == 0){
                    t[i][j] = true;
                    continue;
                }
                else if(i == 0){
                    t[i][j] = false;
                    continue;
                }
                
                if(j < arr[i-1])
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = (t[i-1][j]) || (t[i-1][j - arr[i-1]]);
            }
        }
        
        int minDiffSum = 0;
        for( int i = sum/2; i>=0; i--){
            if(t[n][i] == true){
                minDiffSum = i;
                break;
            }
        }
        
        return sum-2*minDiffSum;
    }
};