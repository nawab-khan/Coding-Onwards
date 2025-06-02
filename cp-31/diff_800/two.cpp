#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, x;
        cin >> n >> x;

        vector<int> vec (n, 0);

        for(int i=0;i<n;i++)
            cin >> vec[i];
        
        int res = max(vec[0], 2*(x - vec[n-1]));

        for(int i=1;i<n;i++)
            res = max(res, vec[i] - vec[i-1]);

        cout << res << endl;
    }

    return 0;
}