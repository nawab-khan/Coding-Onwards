class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        
        int m = nums.size(), n = nums[0].size();

        int l = 0, r = m*n - 1, mid;

        while(l <= r){

            mid = l + (r - l)/2;

            if(nums[mid/n][mid%n] == target){
                return true;
            }
            else if(nums[mid/n][mid%n] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }

            cout << mid << " ";

        }
        return false;
    }
};