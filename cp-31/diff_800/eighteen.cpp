#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int x, k, res = 0;
        cin >> x >> k;

        vector<int> vec;

        while(x){

            if(x%k == 0){
                res += 2;
                vec.push_back(x-1);
                vec.push_back(1);
                x = 0;
            }
            else{
                res++;
                vec.push_back(x);
                x = 0;
            }

        }

        cout << res << endl;
        
        for(int i : vec){
            cout << i << " ";
        }

        cout << endl;
        
    }

    return 0;
}