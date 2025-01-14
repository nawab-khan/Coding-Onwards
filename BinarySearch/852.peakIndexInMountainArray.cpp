class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        int l = 0, r = n - 1, m, res  = -1;

        while(l < r){

            m = l + (r - l)/2;

            if(arr[m] > arr[m + 1] && arr[m] > arr[m - 1])
                return m;

            else if(arr[m] > arr[m + 1]){
                res = m;
                r = m;
            }
            else{
                res = max(res, arr[m]);
                l = m + 1;
            }

        }
        return l;
    }
};