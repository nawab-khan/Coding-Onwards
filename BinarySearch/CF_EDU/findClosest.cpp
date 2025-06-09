#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, k;
    cin >> n >> k;

    vector<int> vec (n);

    for(int i=0;i<n;i++)
        cin >> vec[i];

    int l = 0, r = n - 1, res = INT_MAX, target;
    
    while(k--){

        cin >> target;

        while(l < r){

            int m = (l + r)/2, temp;

            if(vec[m] == target){
                cout << vec[m] << endl;
                break;
            }
            else if(vec[m] > target){
                
                // int temp;
                
                if(abs(target - vec[m-1]) <= abs(target - vec[m]))
                    temp = vec[m-1];
                else
                    temp = vec[m];
                
                r = m - 1;
            }
            else{
                
                // int temp;
                
                if(abs(target - vec[m+1]) < abs(target - vec[m]))
                    temp = vec[m+1];
                else
                    temp = vec[m];

                
                l = m + 1;
            }

            if(abs(temp - target) >= abs(res - target)){
                    // cout << res << endl;
                    break;
                }


        }

        cout << res << endl;

    }
    
    return 0;
}