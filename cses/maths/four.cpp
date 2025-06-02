#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, x, count, inv, i;
    cin >> n;

    while(n--){

        cin >> x;

        count = x == 1 ? 1 : 2;

        for(i = 2;i*i < x;i++){

            if(x%i == 0){
                count++;

                // inv = x/i;
                // cout << i << " ";

                if(x%(x/i) == 0)
                    count++;
            }

        }

        if(i == x/i)
            count++;

        cout << count << endl;

    }
    
    return 0;
}