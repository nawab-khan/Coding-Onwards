#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, k;
        cin >> n >> k;

        bool flag = false;

        vector<int> vec (n, 0);

        for(int i=0;i<n;i++){
            cin >> vec[i];

            if(vec[i] == k){
                flag = true;
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
        
    }

    return 0;
}