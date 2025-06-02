#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){

    int n;
    cin >> n;

    vector<string> grid (n);

    for(int i=0;i<n;i++)
        cin >> grid[i];

    if(grid[0][0] == '*' || grid[n-1][n-1] == '*')
        cout << "0" << endl;
    else{

        vector<vector<int>> t (n, vector<int> (n));
        
        t[0][0] = 1;

        for(int i=1;i<n;i++){
            t[i][0] = (grid[i][0] == '.') && t[i-1][0];
        }

        for(int j=1;j<n;j++){
            t[0][j] = (grid[0][j] == '.') && t[0][j-1];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                
                if(grid[i][j] == '.')
                    t[i][j] = (t[i-1][j] + t[i][j-1])%mod;
                else
                    t[i][j] = 0;

            }
        }

        cout << t[n-1][n-1] << endl;
    }    

}