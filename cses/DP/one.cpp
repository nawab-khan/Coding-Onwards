#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int mod = 1e9 + 7;
int t[1000001];

int helper(int n){

    if(n == 0)
        return 1;

    if(t[n] != -1)
        return t[n];

    int ans = 0;

    for(int i=1;i<=6;i++){
        if(n >= i)
            ans = (ans + helper(n - i)%mod)%mod;
    }
    
    return t[n] = ans;
}

int main(){
    
    memset(t, -1, sizeof(t));

    int n;
    cin >> n;
    
    cout << helper(n);
}