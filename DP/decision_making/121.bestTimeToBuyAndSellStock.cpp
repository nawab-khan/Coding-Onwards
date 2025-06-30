class Solution {
public:
    int t[100001];

    int helper(vector<int>& p, int index){

        if(index >= p.size())
            return 0;
        
        if(t[index] != -1)
            return t[index];

        int ans = helper(p, index+1);

        for(int i=index+1;i<p.size();i++)
            ans = max(ans, (p[i] - p[index]));

        return t[index] = ans;
    }

    int maxProfit(vector<int>& prices) {

        memset(t, -1, sizeof(t));

        return helper(prices, 0);
    }
};