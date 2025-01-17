class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        
        int n = derived.size();

        vector<int> arr (n,1);

        for(int i=0;i<n-1;i++){

            if(derived[i])
                arr[i+1] = 1 - arr[i];
            else
                arr[i+1] = arr[i];

        }

        if(derived[n-1] && arr[0] == arr[n-1] || derived[n-1] == 0 && arr[0] != arr[n-1])
                return false;

        return true;

    }
};