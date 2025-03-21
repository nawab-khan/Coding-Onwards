int t[1001][1001];

int helper(int& n, int val, bool cf, int cop){

    if(n == val)
        return 0;

    if(val > n)
        return 2000;

    if(t[val][cop] != -1)
        return t[val][cop];

    
    int c = INT_MAX - 1, p = INT_MAX - 1;

    if(!cf)
        c = 2 + helper(n, 2*val, true, val);

    if(cop)    
        p = 1 + helper(n, val + cop, false, cop);

    return t[val][cop] = min(c, p);

}

int minSteps(int n) {
    
    memset(t, -1, sizeof(t));

    return helper(n, 1, false, 0);

}