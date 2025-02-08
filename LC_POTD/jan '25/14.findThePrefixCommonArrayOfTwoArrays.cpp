class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n = A.size();

        vector<int> freq (n+1,0);
        vector<int> res (n,0);

        for(int i=0;i<n;i++){

            freq[A[i]]++;

            int count = 0;

            for(int j=0;j<=i;j++)
                if(freq[B[j]])
                    count++;

            res[i] = count;

        }


        return res; 

    }
};