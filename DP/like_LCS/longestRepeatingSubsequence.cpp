class Solution {
public:
    int LongestRepeatingSubsequence(string &s) {
        
        int n = s.length();
        
        string res = "";
        
        int t[n+1][n+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                    continue;
                }
                
                if(s[i-1] == s[j-1] && i != j){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
                
            }
        }

        // --------------------printing LRS------------------------
        // int i = n, j = n;
        
        // while(i && j){
        //     if(s[i-1] == s[j-1] && i != j){
        //         res = s[i-1] + res;
        //         i--;
        //         j--;
        //     }
        //     else if(t[i-1][j] > t[i][j-1]){
        //         i--;
        //     }
        //     else{
        //         j--;
        //     }
        // }

        // cout << res;
        
        return res.length();
    }
};