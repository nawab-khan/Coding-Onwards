class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size(), max = INT_MIN, min = INT_MAX;

        for(int i : nums){
            if(i > max)
                max = i;
            if(i < min)
                min = i;
        }

        int l = min, r = max, m, res = -1;
        long long available;

        while(l <= r){

            vector<long long> temp (n, 0);
            for(int i=0;i<n;i++)
                temp[i] = nums[i];
            
            m = l + (r - l)/2;
            bool flag = true;

            for(int i=1;i<n;i++){

                available = m - temp[i-1];

                if(available < 0){
                    l = m + 1;
                    flag = false;
                    break;
                }
                
                temp[i] -= available;

            }

            if(temp[n-1] > m){
                l = m + 1;
                flag = false;
            }
                

            // found an answer, and now we move left to check if a smaller answer is possible
            if(flag){
                res = m;
                r = m - 1;
            }

        }

        return res;

    }
};