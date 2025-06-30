class Solution {
public:
    int t[1001][101][2];
    int helper(int index, int k, bool state, vector<int>& prices){
        
        // bc
        if(index >= prices.size() || k < 0){
            return 0;
        }

        if(t[index][k][state] != -1)
            return t[index][k][state];

        int ans = helper(index + 1, k, state, prices);

        if(state){ // selling
            ans = max(ans, helper(index + 1, k, false, prices) + prices[index]);
        }
        else{ // buying
            ans = max(ans, helper(index + 1, k - 1, true, prices) - prices[index]);
        }

        return t[index][k][state] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        
        memset(t, -1, sizeof(t));

        return helper(0, k, false, prices);
    }
};