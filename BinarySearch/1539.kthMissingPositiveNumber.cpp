class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int l = 0, r = n - 1, m, miss;

        while(l <= r){

            m = l + (r - l)/2;

            // # of missing numbers for arr[m]
            miss = arr[m] - (m + 1); 

            if(miss < k)
                l = m + 1;
            else
                r = m - 1;

        }

        /*
        we get 'l' as the index that contains the upper bound on the misssing values.
        i.e. for arr = [2,3,4,7,11] & k = 5 : l comes out to be 4
        Hence, to the left of index 4, there are 4 elements that are present in the array and some missing(6)
        So, in order to get the 5th missing number: we add (numbers on the left of index l (= l) and 
                                                    the number of missing values).

            5th missing value : l + k = (4 + 5) = 9
        */
        return l + k;

    }
};