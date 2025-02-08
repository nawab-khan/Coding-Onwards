class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size(), count = 0;

        vector<long long> pSum (n,0);
        long long sum = 0;

        for(int i=0;i<n;i++){

            pSum[i] = sum;

            sum += nums[i];

        }

        for(int i=1;i<n;i++){

            if(pSum[i] >= sum - pSum[i])
                count++;

        }

        return count;
    }
};