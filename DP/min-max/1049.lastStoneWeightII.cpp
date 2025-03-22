int lastStoneWeightII(vector<int>& stones) {

    //we want subsets with minimum difference 
    //instead of picturing each collision, think of putting them into two buckets such that we keep colliding the stones
    //taking one from both of them and this goes on until there are only stones left in one bucket.
    //subset difference is that weight. * We need the minimum of these subset differences *
    
    int n = stones.size(), sum = 0;

    for(int i : stones)
        sum += i;
    
    vector<vector<int>> t (n + 1, vector<int> (sum + 1));

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){

            if(j == 0){
                t[i][j] = 1;
            }
            else if(i == 0){
                t[i][j] = 0;
            }
            else{

                if(stones[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] || t[i-1][j - stones[i-1]];

            }

        }
    }

    int res = INT_MAX;
    for(int i=0;i<=sum/2;i++){

        if(t[n][i] == 1 && t[n][sum - i] == 1){
            res = min(res, sum - 2*i);
        }

    }

    return res;
}