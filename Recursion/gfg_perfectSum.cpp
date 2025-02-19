#include <iostream>
using namespace std;

void func(vector<int>& arr, int s, int sum, int& count, int target){
    
    if(arr.size() == s){
        if(sum == target)
            count++;

        return;
    }
    
    int ele = arr[s];
    
    func(arr, s+1, sum, count, target);
    
    func(arr, s+1, sum + ele, count, target);
    
}

int perfectSum(vector<int>& arr, int target) {
    
    int count = 0;
    
    func(arr, 0, 0, count, target);
    
    return count;
}

int main(){
    
    int n, ele;
    cin >> n;

    vector<int> arr (n, 0);

    for(int i=0;i<n;i++){
        cin >> ele;
        arr[i] = ele;
    }

    int target;
    cin >> target;

    int a = perfectSum(arr, target);

    cout << a;
    
    return 0;
}