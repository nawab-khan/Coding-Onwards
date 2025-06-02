bool canPartition(vector<int>& nums) {
        
    int n = nums.size(), sum = 0;

    for(int i : nums)
        sum += i;

    if(sum&1)
        return false;

    vector<vector<int>> t (n+1, vector<int> (sum/2+1));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum/2+1;j++){

            if(j == 0){
                t[i][j] = 1;
                continue;
            }
            if(i == 0){
                t[i][j] = 0;
                continue;
            }

            if(nums[i-1] > j)
                t[i][j] = t[i-1][j];
            else
                t[i][j] = t[i-1][j] || t[i-1][j - nums[i-1]];

        }
    }

    return t[n][sum/2];
}