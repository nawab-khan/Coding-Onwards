#include <iostream>

using namespace std;

void insert(vector<int>& nums, int n, int ele){

    if(n == 0 || nums[n - 1] <= ele){
        nums.push_back(ele);
        return;
    }
    
    int val = nums[n-1];
    nums.pop_back();

    insert(nums, n - 1, ele);

    nums.push_back(val);

}

void sortArray(vector<int>& nums, int n) {
    
    if(n == 0)
        return;

    int ele = nums[n - 1];
    nums.pop_back();

    sortArray(nums, n - 1);

    insert(nums, n - 1, ele);

}

int main(){

    int n;
    cin >> n;

    vector<int> nums (n , 0);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    sortArray(nums, nums.size());
    
    for(int i : nums)
        cout << i <<  " ";
   

    return 0;
}