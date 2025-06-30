class Solution {
public:
    int t[50001][2];
    int helper(int index, bool state, vector<int>& prices, int& fee){
        
        //bc
        if(index >= prices.size())
            return 0;
        
        if(t[index][state] != -1)
            return t[index][state];
        
        int ans = helper(index + 1, state, prices, fee);

        if(state){ // selling
            ans = max(ans, helper(index + 1, false, prices, fee) + prices[index] - fee);
        }
        else{ // buying
            ans = max(ans, helper(index + 1, true, prices, fee) - prices[index]);
        }
    
        return t[index][state] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(t, -1, sizeof(t));

        return helper(0, false, prices, fee);
    }
};