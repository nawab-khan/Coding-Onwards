class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        int l = 1, r = maxSum, m, res = 0;

        while(l <= r){

            m = l + (r - l)/2;

            long long left_count = min(index, m - 1);

            long long left_sum = (left_count*m) - (left_count*(left_count + 1))/2;

            left_sum += max(0, index - (m - 1));    



            long long right_count = min(n - index - 1, m - 1);

            long long right_sum = right_count*m - (right_count*(right_count + 1))/2;

            right_sum += max(0, n - index - 1 - (m - 1));
             

            long long sum = left_sum + right_sum + m;

            if(sum <= maxSum){
                res = max(res,m);
                l = m + 1;
            }
            else{
                r = m - 1;
            }

        }

        return res;
    }
};
