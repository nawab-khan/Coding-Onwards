class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return binarySearch(nums, target, 0, nums.size()-1);

    }

    int binarySearch(vector<int>& nums, int target, int l, int r){

        if(l > r)
            return -1;

        int m = l + (r - l)/2;

        if(nums[m] > target)
            return binarySearch(nums,target,l,m-1);

        else if(nums[m] < target)
            return binarySearch(nums,target,m+1,r);
        
        else
            return m;
    }

};
