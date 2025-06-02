#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;

        vector<int> vec (n, 0);
        vector<int> res;

        cin >> vec[0];
        res.push_back(vec[0]);

        for(int i=1;i<n;i++){
            cin >> vec[i];

            if(vec[i] >= vec[i-1]){
                res.push_back(vec[i]);
            }
            else{
                res.push_back(1);
                res.push_back(vec[i]);
            }
        }
        
        int m = res.size();

        cout << m << endl;

        for(int i=0;i<m;i++)
            cout << res[i] << " ";
        
        cout << endl;
        
    }

    return 0;
}