class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int l = 0, r = n - 1, m;

        while(l < r){

            m = l + (r - l)/2;

            if(nums[m] == nums[m+1]){
                if((r-m)%2 == 0){
                    l = m + 2;
                }
                else{
                    r = m - 1;
                }
            }

            else {
                if((r-m)%2 == 0){
                    r = m;
                }
                else{
                    l = m + 1;
                }
            }

        }
            return nums[r];
        
    }
};