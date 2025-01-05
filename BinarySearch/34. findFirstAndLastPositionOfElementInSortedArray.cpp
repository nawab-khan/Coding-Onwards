class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<int> res (2,-1);

        if(n == 0)
            return res;
        
        if(n == 1){
            if(nums[0] == target)
                res[0] = 0, res[1] = 0;
        
            return res;
        }

        int l = 0, r = n-1, m, s = -1, e = -1;

        while(l <= r){
            
            m = l + (r - l)/2;

            if(nums[m] == target){
                s = m;
                r = m - 1;
            }

            else if(nums[m] < target){
                l = m + 1; 
            }

            else {
                r = m - 1;
            }

        }

    l = 0, r = n - 1;

        while(l <= r){
            
            m = l + (r - l)/2;

            if(nums[m] == target){
                e = m;
                l = m + 1;
            }

            else if(nums[m] < target){
                l = m + 1; 
            }

            else {
                r = m - 1;
            }

        }

        res[0] = s, res[1] = e;

        return res;

    }
};