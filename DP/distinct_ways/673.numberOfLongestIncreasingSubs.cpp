class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size(), m = 1, res = 0;

        vector<int> t (n, 1), count (n, 1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){

                if(nums[i] > nums[j] && t[i] < t[j] + 1){
                    t[i] = t[j] + 1;
                    count[i] = count[j];
                }
                else if(nums[i] > nums[j] && t[i] == t[j] + 1)
                    count[i] += count[j];

                m = max(m, t[i]);
            }
        }

        for(int i=0;i<n;i++)
            if(t[i] == m)
                res += count[i];

        return res;
    }
};