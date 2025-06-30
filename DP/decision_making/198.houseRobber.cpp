class Solution {
public:
    int t[101];

    int helper(vector<int>& nums, int i){

        //bc
        if(i >= nums.size()){
            return 0;
        }

        if(t[i] != -1)
            return t[i];

        int res = helper(nums, i+1);
        
        return t[i] = max(res, nums[i] + helper(nums, i+2));
    }

    int rob(vector<int>& nums) {
        
        memset(t, -1, sizeof(t));

        return helper(nums, 0);
    }
};