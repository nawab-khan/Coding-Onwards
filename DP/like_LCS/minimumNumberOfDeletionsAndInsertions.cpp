class Solution {
public:
    int minOperations(string &s1, string &s2) {
        
        int n = s1.length(), m = s2.length(), i, j;
        
        int t[n+1][m+1];
        
        for(i=0;i<n+1;i++){
            for(j=0;j<m+1;j++){
                
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
                
            }
        }
        
        return n + m - 2*t[n][m];
    }
};