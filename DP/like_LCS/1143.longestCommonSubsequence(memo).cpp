class Solution {
public:

    int t[1001][1001];

    int helper(string &s1, string &s2, int n, int m){
        
        //bc
        if(n == 0 || m == 0){
            return 0;
        }
        
        if(t[n][m] != -1){
            return t[n][m];
        }
        
        if(s1[n-1] == s2[m-1]){
            return t[n][m] = 1 + helper(s1, s2, n - 1, m - 1);
        }
        else{
            return t[n][m] = max(helper(s1, s2, n - 1, m), helper(s1, s2, n, m - 1));
        }
        
    }

    int lcs(string &s1, string &s2) {
        
        memset(t, -1, sizeof(t));
        
        int n = s1.length(), m = s2.length();
        
        // int t[n+1][m+1];
        
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
                
        //         if(i == 0 || j == 0){
        //             t[i][j] = 0;
        //             continue;
        //         }
                
        //         if(s1[i-1] == s2[j-1]){
        //             t[i][j] = 1 + t[i-1][j-1];
        //         }
        //         else{
        //             t[i][j] = max(t[i-1][j], t[i][j-1]);
        //         }
                
        //     }
        // }
        
        // return t[n][m];
        
        return helper(s1, s2, n, m);
        
    }
};