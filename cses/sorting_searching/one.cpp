#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;

    vector<int> vec (n);

    for(int i=0;i<n;i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    int j = 0;

    for(int i=0;i<n;i++){
        
        if(vec[i] > vec[j]){
            ++j;
            vec[j] = vec[i];
        }

    }

    cout << j + 1;

    return 0;
}