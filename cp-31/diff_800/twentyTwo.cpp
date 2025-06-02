#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b){

    if(b == 0)
        return a;
    
    return gcd(a, b%a);
    
}

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        long long n, k;
        cin >> n >> k;

        if(n%2 == 0)
            cout << "YES" << endl;
        else if(k%2 == 0 && n&1)
            cout << "NO" << endl;
        else{

            long long x = 0;
            
            while(x <= n/2){

                if((n - 2*x)%k == 0){
                    cout << "YES" << endl;
                    break;
                }

                x++;

            }

            if(x > n/2)
                cout << "NO" << endl;

        }
        
    }

    return 0;
}