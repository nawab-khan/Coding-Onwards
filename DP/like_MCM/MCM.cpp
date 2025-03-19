#include <iostream>
using namespace std;

int helper(vector<int> &arr, int i, int j){
    
    if(i >= j)
        return 0;
    
    int res = INT_MAX;
    
    for(int k=i;k<j;k++){
        
        int temp = helper(arr, i, k) + helper(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        
        res = min(res, temp);
    }
    
    return res;
}

int matrixMultiplication(vector<int> &arr) {
    
    int n = arr.size();
    
    return helper(arr, 1, n-1);
    
    // for(int i = 1;i < n;i++){
        
    // }
    
}

int main(){
    
    int n;
    cin >> n;

    vector<int> vec(n, 0);

    for(int i=0;i<n;i++){
        cin >> vec[i];
    }

    cout << matrixMultiplication(vec);
    
    return 0;
}