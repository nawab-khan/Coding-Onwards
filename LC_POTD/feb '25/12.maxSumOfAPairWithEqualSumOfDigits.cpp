class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        int n = nums.size(), res = -1;

        map<int, int> digits, digits2;

        for(int i=0;i<n;i++){

            string str = to_string(nums[i]);
            int j = 0, sum = 0, len = str.length();

            while(j < len)
                sum += (str[j++] - '0');

            if(digits.find(sum) != digits.end()){
                if(digits2.find(sum) != digits.end()){
                    
                    int a = digits[sum], b = digits2[sum], c = nums[i];

                    if(c > a){
                        digits[sum] = c;
                        c = a;
                    }

                    if(c > b){
                        digits2[sum] = c;
                    }

                }
                else{
                    digits2.insert({sum,nums[i]});
                }

                res = max(res, digits[sum] + digits2[sum]);

            }
            else{
                digits.insert({sum,nums[i]});
            }

        }

        return res;
    }
};