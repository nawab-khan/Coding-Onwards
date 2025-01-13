class Solution {
public:

    long long calcSum(vector<int>& nums, vector<int>& cost, int m, int n){

        long long sum = 0;

        for(int i=0;i<n;i++)
            sum += (long long)cost[i]*(abs)(nums[i] - m);

        return sum;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size(), min = 0, max  = 0;
        long long res = LLONG_MAX;

        for(int i=1;i<n;i++){
            
            if(nums[i] > nums[max])
                max = i;

            if(nums[i] < nums[min])
                min = i;

        }

        int l = nums[min], r = nums[max], m;

        while(l <= r){

            m = l + (r - l)/2;

            long long sum = calcSum(nums, cost, m, n);

            if(sum < calcSum(nums, cost, m + 1, n))
                r = m - 1;
            else
                l = m + 1;

            if(sum < res)
                res = sum;
        }

        return res;
    }

};