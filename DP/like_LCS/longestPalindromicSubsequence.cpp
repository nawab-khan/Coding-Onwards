class Solution {
public:
    int longestPalinSubseq(string &s) {
        
        int n = s.length();
        
        string s1 = s;
        reverse(s1.begin(), s1.end());
        
        int t[n+1][n+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(s[i-1] == s1[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
                
            }
            
        }
        
        return t[n][n];
    }
};