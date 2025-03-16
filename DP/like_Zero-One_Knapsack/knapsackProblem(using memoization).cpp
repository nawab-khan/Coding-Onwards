class Solution {
public:

    // dp table
    int t[1001][1001];
    
    int helper(int W, int n, vector<int> &val, vector<int> &wt){
        
        // bc
        if(n == 0 || W == 0){
            return 0;
        }
        
        if(t[n][W] != -1)
            return t[n][W];
        
        if(wt[n-1] > W)
            return t[n][W] = helper(W, n-1, val, wt);
        
        return t[n][W] = max(helper(W, n-1, val, wt), val[n-1] + helper(W - wt[n-1], n-1, val, wt));
    }
    
    int knapSack(int W, vector<int> &val, vector<int> &wt) {
        
        //dp table initialization
        memset(t, -1, sizeof(t));
        
        return helper(W, val.size() , val, wt);
    }
};