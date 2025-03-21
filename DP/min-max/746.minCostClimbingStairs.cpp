int t[1001];

int helper(vector<int>& cost, int i){

    if(i == cost.size()){
        return 0;
    }

    if(t[i] != -1){
        return t[i];
    }

    if(i == cost.size()-1){
        return cost[i];
    }
    else{
        return t[i] = cost[i] + min(helper(cost, i+1), helper(cost, i+2));
    }

}

int minCostClimbingStairs(vector<int>& cost) {
    
    memset(t, -1, sizeof(t));

    return min(helper(cost, 0), helper(cost, 1));
}