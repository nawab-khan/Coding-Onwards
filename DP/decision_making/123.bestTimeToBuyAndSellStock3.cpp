class Solution {
public:
    int t[100001][3][2];
    int helper(vector<int>& p, int k, bool state, int index, int b){

        //bc
        if(index >= p.size() || k < 0){
            return 0;
        }
        
        if(t[index][k][state] != -1)
            return t[index][k][state];

        int res = helper(p, k, state, index + 1, b);

        if(state){

            res = max(res, p[index] + helper(p, k, false, index + 1, b));

        }
        else{

            res = max(res, helper(p, k - 1, true, index + 1, index) - p[index]);

        }

        return t[index][k][state] = res;

    }

    int maxProfit(vector<int>& prices) {
        memset(t, -1, sizeof(t));

        return helper(prices, 2, false, 0, 0);    
    }
};