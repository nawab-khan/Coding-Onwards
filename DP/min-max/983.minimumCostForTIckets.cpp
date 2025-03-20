int t[366];

int helper(vector<int>& days, vector<int>& costs, int i){

    if(i >= days.size()){
        return 0;
    }

    if(t[i] != -1){
        return t[i];
    }

    int o, s, m;

    o = costs[0] + helper(days, costs, i+1);

    int j = i;
    while (j < days.size() && days[j] < days[i] + 7) 
        j++;
    s = costs[1] + helper(days, costs, j);
    
    j = i;
    while (j < days.size() && days[j] < days[i] + 30)
        j++;
    m = costs[2] + helper(days, costs, j);

    return t[i] = min(o, min(s, m));


}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    
    memset(t, -1, sizeof(t));

    return helper(days, costs, 0);
}