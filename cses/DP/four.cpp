#include <bits/stdc++.h>

// #include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main(){

    // int mod = 1e9 + 7;

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int&v : coins) cin >> v;

    vector<int> t(x + 1, 0);

    t[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){

            if(j >= coins[i])
                t[j] = (t[j] + t[j - coins[i]])%mod;

        }
    }

    cout << t[x] << "\n";
}