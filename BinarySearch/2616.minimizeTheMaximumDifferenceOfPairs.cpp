class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size(), l = 0, r = nums[nums.size()-1] - nums[0], m, res = INT_MAX, count;

        while(l <= r){

            m = l + (r - l)/2;
            count = 0;

            for(int i=0;i<n-1;){

                if(abs(nums[i] - nums[i+1]) <= m){
                    count++;
                    i += 2;
                }
                else
                    i++;

            }

            if(count >= p){
                res = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }

        }

        return res;

    }
};