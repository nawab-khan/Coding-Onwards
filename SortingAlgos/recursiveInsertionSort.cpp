#include <bits/stdc++.h>
using namespace std;

void insertFunc(vector<int>& arr, int e){
    
    // bc
    if(e == 0)
        return;
    
    if(arr[e] < arr[e-1]){
        swap(arr[e], arr[e-1]);
        
        insertFunc(arr, e - 1);
    }
    
}

void helper(vector<int>& arr, int e){
    
    // bc
    if(e == arr.size())
        return;
        
    insertFunc(arr, e);
    
    helper(arr, e+1);
}

void insertionSort(vector<int>& arr) {
    helper(arr, 0);
}

int main(){

    int n;
    cin >> n;

    vector<int> vec (n);

    for(int &i : vec)
        cin >> i;

    insertionSort(vec);

    for(int i : vec)
        cout << i << " ";

    return 0;
}