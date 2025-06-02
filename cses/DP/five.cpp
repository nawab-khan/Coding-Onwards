#include <bits/stdc++.h>

using namespace std;

int t[1000001];

int helper(int n){

    if(n < 10)
        return n > 0;

    if(t[n] != -1)
        return t[n];

    int x = n, ans = INT_MAX;

    while(x){

        if(x%10)
            ans = min(ans, 1 + helper(n - x%10));
        
        x /= 10;
    }

    return t[n] = ans;

}

int main(){

    memset(t, -1, sizeof(t));

    int n;
    cin >> n;

    cout << helper(n);

}