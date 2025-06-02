#include <bits/stdc++.h>

using namespace std;

// const int mod = 1e9 + 7;

// // int t[100001][1001];

// // int helper(int i, int x, vector<int>& price, vector<int>& pages){

// //     if(x == 0 || i >= price.size())
// //         return 0;
    
// //     if(t[i][x] != -1)
// //         return t[i][x];
    
// //     int ans = helper(i + 1, x, price, pages);

// //     if(x >= price[i])
// //         ans = max(pages[i] + helper(i+1, x - price[i], price, pages), ans);

// //     return t[i][x] = ans;
// // }

int main(){

    // memset(t, -1, sizeof(t));

    int n, x;
    cin >> n >> x;

    vector<int> price (n), pages (n);

    for(int i=0;i<n;i++)
        cin >> price[i];

    for(int i=0;i<n;i++)
        cin >> pages[i];
    
    // cout << helper(0, x, price, pages);

    vector<vector<int>> t ;

}