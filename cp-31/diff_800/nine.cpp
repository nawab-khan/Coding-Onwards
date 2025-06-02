#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, ele, sum = 0;
        cin >> n;

        for(int i=1;i<n;i++){
            cin >> ele;

            sum -= ele;
        }
        
        cout << sum << endl;
        
    }

    return 0;
}