class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        
    int n = arr.size(), sum = 0;
    
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++){

        for(int j=0;j<sum+1;j++){

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
            else
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];

        }
        
    }

    int count = 0;
    for(int i=0;i<=sum;i++){
        if(sum - 2*i == diff){
            count += t[n][i];
        }
    }
    
    return count;

    }
};