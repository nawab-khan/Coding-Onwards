class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size(), sum = 0;

        for(int i : nums)
            sum += i;

        int t[21][1001];

        for(int i=0;i<n+1;i++){

            for(int j=0;j<sum+1;j++){

                if(i==0 && j==0){
                    t[i][j] = 1;
                    continue;
                }
                else if(i==0){
                    t[i][j] = 0;
                    continue;
                }

                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i-1][j - nums[i-1]];

            }

        }

        int count = 0;
        for(int i=0;i<=sum;i++){

            if(2*i - sum == target)
                count += t[n][i];

        }

        return count;
    }
};