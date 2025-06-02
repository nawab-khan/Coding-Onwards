#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){
    
    int n;
    long long a, b, c, res1, res2;
    cin >> n;

    while(n--){

        cin >> a >> b >> c;

        if(c == 0)
            cout << (a==0 ? 0 : a) << endl;
        else if(b == 0)
            cout << 1 << endl;
        else if(a == 0)
            cout << 0 << endl;
        else{

            res1 = 1;

            while(c){

                if(c&1){
                    res1 = (res1 * b)%(mod-1);
                    c--;
                }
                else{
                    b = (b*b)%(mod-1);
                    c >>= 1;
                }

            }

            // b = res%(mod - 1);
            
            res2 = 1;

            while(res1){

                if(res1&1){
                    res2 = (res2 * a)%mod;
                    res1--;
                }
                else{
                    a = (a*a)%mod;
                    res1 >>= 1;
                }

            }

            // b = res%(mod - 1);



            cout << res2 << endl;

        }

    }
    
    return 0;
}