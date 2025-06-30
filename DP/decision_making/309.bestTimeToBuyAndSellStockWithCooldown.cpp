class Solution {
public:
    int t[5001][2];
    int helper(int index, bool state, vector<int>& prices){

        //bc
        if(index >= prices.size()){
            return 0;
        }

        if(t[index][state] != -1)
            return t[index][state];

        int ans = helper(index + 1, state, prices);

        if(state){ // selling
            ans = max(ans, helper(index + 2, false, prices) + prices[index]);
        }
        else{ // buying
            ans = max(ans, helper(index + 1, true, prices) - prices[index]);
        }

        return t[index][state] = ans;

    }

    int maxProfit(vector<int>& prices) {
        
        memset(t, -1, sizeof(t));

        return helper(0, false, prices);
    }
};