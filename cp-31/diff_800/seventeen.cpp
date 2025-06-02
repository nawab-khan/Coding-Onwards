#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, k, x;
        cin >> n >> k >> x;

        vector<int> res;

        if(k == 1 && x == 1 || n&1 && k == 2 && x == 1){
            cout << "NO";
            continue;
        }

        while(n){

            if(n >= k){
                n -= k;
                res.push_back(k);
            }
            else if(n == x){
                n--;
                res.push_back(1);
            }
            else{
                n = 0;
                res.push_back(n);
            }


        }



        
    }

    return 0;
}