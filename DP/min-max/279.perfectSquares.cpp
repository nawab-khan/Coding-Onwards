// int t[10001];

// int helper(int n){
            
//     if(n <= 1)
//         return n;

//     if(t[n] != -1)
//         return t[n];

//     int res = INT_MAX;

//     for(int i=1;i*i<=n;i++){

//         int ans = 1 + helper(n - i*i);

//         res = min(res, ans);
//     }

//     return t[n] = res;
// }

int numSquares(int n) {
    
    // memset(t, -1, sizeof(t));

    if(n <= 1)
        return n;

    vector<int> t(n+1, INT_MAX);

    for(int i=0;i<=n;i++){

        if(i <= 1){
            t[i] = i;
            continue;
        }

        // int ans = 1 + helper(n - i*i);
        for(int k=1;k*k<=i;k++)
            t[i] = min(t[i], 1 + t[i - k*k]);

    }

    // return helper(n);
    return t[n];
}