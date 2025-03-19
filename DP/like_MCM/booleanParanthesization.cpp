class Solution {
public:
    
    int t[101][101][2];
    
    int helper(string& s, int i, int j, bool isTrue){

        if(i > j){
            return 0;
        }
        
        if(t[i][j][isTrue] != -1)
            return t[i][j][isTrue];
        
        if(i == j){
            if(isTrue)
                return t[i][j][1] = s[i] == 'T';
            else
                return t[i][j][0] = s[i] == 'F';
        }
        
        
        int ans = 0;
        
        //memo
        
        for(int k=i+1;k<j;k+=2){
            
            int lT = helper(s, i, k-1, true);
            int lF = helper(s, i, k-1, false);
            int rT = helper(s, k+1, j, true);
            int rF = helper(s, k+1, j, false);
            
            if(s[k] == '&'){
                if(isTrue)
                    ans = ans + lT*rT;
                else
                    ans = ans + lF*rF + lT*rF + lF*rT;
            }
            else if(s[k] == '|'){
                if(isTrue)
                    ans = ans + lT*rT + lT*rF + lF*rT;
                else
                    ans = ans + lF*rF;
            }
            else if(s[k] == '^'){
                if(isTrue)
                    ans = ans + lT*rF + lF*rT;
                else
                    ans = ans + lT*rT + lF*rF;
            }    
        }
        
        return t[i][j][isTrue] = ans;
    }
    
    int countWays(string s) {
        
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        
        return helper(s, 0, n-1, true);
        
    }
};