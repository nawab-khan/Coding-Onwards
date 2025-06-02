#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, a, b;
        cin >> n >> a >> b;

        if(a + b < n-1 || a==n && b==n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
    }

    return 0;
}