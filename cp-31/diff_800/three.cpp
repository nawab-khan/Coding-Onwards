#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, res;
        cin >> n;

        string str;
        cin >> str;

        int count = (str[0] == '.'), threeDot = 0;

        for(int i=1;i<n-1;i++){

            if(str[i] == '.'){
                count++;
            
                if(str[i-1] == '.' && str[i+1] == '.')
                    threeDot++;
            }
        }
        
        if(n != 1)
            count += (str[n-1] == '.');

        if(threeDot == 0){
            res = count;
        }
        else{
            res = 2;
        }

        cout << res << endl;
        
    }

    return 0;
}