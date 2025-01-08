class Solution {
public:

    bool binarySearch(vector<int>& nums, int target, int l, int r){

        while(l < r){

            int m = l + (r - l)/2;

            if(nums[m] == target)
                return true;
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;

        }

        return (nums[l] == target);


    }

    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0, r = n - 1, m;

        // fo removing duplicate elemnts from both sides and narrow the search
        while(l < r && nums[l] == nums[l+1])
            l++;

        while(l < r && nums[r] == nums[r-1])
            r--;

        // to find the pivot index
        while(l < r){

            m = l + (r - l)/2;

            if(nums[m] > nums[r])
                l = m+1;
            else
                r = m;

        }


        //searching in both halves created by the pivot
        if(binarySearch(nums,target,0, l-1))
            return true;
        
        if(binarySearch(nums,target,l, n-1))
            return true;
        
        return false;

    }
};