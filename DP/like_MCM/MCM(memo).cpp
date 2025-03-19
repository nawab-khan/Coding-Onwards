class Solution {
public:
    
    int t[101][101];

    int helper(vector<int> &arr, int i, int j){
        
        if(i >= j)
            return 0;
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        int res = INT_MAX;
        
        for(int k=i;k<j;k++){
            
            int temp = (t[i][k] = helper(arr, i, k)) + (t[k+1][j] = helper(arr, k+1, j)) + arr[i-1] * arr[k] * arr[j];
            res = min(res, temp);
        }
        
        return t[i][j] = res;
    }

    int matrixMultiplication(vector<int> &arr) {
        
        memset(t, -1, sizeof(t));

        return helper(arr, 1, arr.size()-1);
    }
};