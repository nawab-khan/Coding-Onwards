class Solution {
public:

    // 100*1000/2 + 1 = 50001
    int t[101][50001];
    
    int helper(int n, vector<int>& arr, int target){
        
        //bc
        if(target == 0){
            return 1;
        }
        if(n == 0){
            return 0;
        }
        
        if(t[n][target] != -1){
            return t[n][target];
        }
        
        if(arr[n-1] > target){
            return t[n][target] = helper(n-1, arr, target);
        }
        
        return t[n][target] = helper(n-1, arr, target) || helper(n-1, arr, target - arr[n-1]);
    }
    
    bool equalPartition(vector<int>& arr) {
        
        memset(t, -1, sizeof(t));
        
        int n = arr.size(), sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        if(sum&1)
            return false;
        
        return helper(n, arr, sum/2);
        
    }
};