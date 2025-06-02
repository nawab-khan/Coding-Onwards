#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, count = 0;
        cin >> n;
        
        vector<int> vec (n, 0);
        
        for(int i=0;i<n;i++){
            cin >> vec[i];

            if(i > 0 && vec[i] > vec[i-1])
                count++;

        }
        
        if(count == n-1){
            cout << "YES" << endl;
        }
        else if(count == 0){
            cout << "NO" << endl;
        }
        else{
            
            bool flag = true;

            while(flag){

                bool changes = false;

                for(int i=1;i<n-1;i++){

                    if(vec[i] > vec[i+1] && vec[i] > vec[i+1]){
                        swap(vec[i], vec[i+1]);
                        changes = true;
                    }

                }

                if(!changes)
                    flag = false;

            }

            count = 0;
            for(int i=0;i<n;i++){

                if(i > 0 && vec[i] > vec[i-1])
                    count++;

            }

            if(count == n-1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

        }

    }

    return 0;
}