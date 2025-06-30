class Solution {
public:
    int t[1001];

    int helper(vector<int>& nums, int target, int& n){

        if(target <= 0)
            return target == 0;
        
        if(t[target] != -1)
            return t[target];

        int ans = 0;

        for(int i=0;i<n;i++){

            if(nums[i] <= target)
                ans += helper(nums, target - nums[i], n);

        }

        return t[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        memset(t, -1, sizeof(t));

        int n = nums.size();

        return helper(nums, target, n);
    }
};