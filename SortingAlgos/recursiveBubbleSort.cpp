#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& arr, int s, int e){
        
        if(s == 0 && e == 0)
            return;
        
        if(s == e){
            helper(arr, 0, e - 1);
            return;
        }    
        
        if(arr[s] > arr[s+1])
            swap(arr[s], arr[s+1]);
            
        helper(arr, s+1, e);
        
}
    
// Function to sort the array using bubble sort algorithm.
void bubbleSort(vector<int>& arr) {
    
    int n = arr.size();
    
    helper(arr, 0, n - 1);
    
}

int main(){

    int n;
    cin >> n;

    vector<int> vec (n);

    for(int &i : vec)
        cin >> i;

    bubbleSort(vec);

    for(int i : vec)
        cout << i << " ";

    return 0;
}