#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){
    
    int n;
    long long a, b, res;
    cin >> n;

    while(n--){

        cin >> a >> b;

        if(b == 0)
            cout << 1 << endl;
        else if(a == 0)
            cout << 0 << endl;
        else{

            res = 1;

            while(b){

                if(b&1){
                    res = (res * a)%mod;
                    b--;
                }
                else{
                    a = (a*a)%mod;
                    b >>= 1;
                }

            }

            cout << res << endl;
        }

    }
    
    return 0;
}