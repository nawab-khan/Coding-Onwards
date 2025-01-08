class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0, r = n - 1, m;

        // To find the index of minimum value or the pivot index 
        while(l < r){

            m = l + (r - l)/2;

            if(nums[m] > nums[r]){
                l = m + 1;
            }
            else{
                r = m;
            }

        }

        r = l - 1 + n;

        // To search the target element
        while(l < r){

            m = l + (r - l)/2;

            if(nums[m%n] == target)
                return m%n;
            else if(nums[m%n] < target)
                l = m + 1;
            else
                r = m - 1;

        }

        return (nums[l%n] == target ? l%n : -1);
    }
};