class Solution {
public:
    int t[1000][1000];
    
    bool checker(string &str, int s, int e){
        
        while(s < e){
            
            if(str[s++] != str[e--]){
                return false;
            }
            
        }
        
        return true;        
    }
    
    int helper(string &s, int i, int j){
        
        if(i >= j){
            return 0;
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        if(checker(s, i, j)){
            return 0;
        }
        
        int res = INT_MAX;
        
        for(int k=i;k<j;k++){
            
            if(checker(s, i, k)){
                int temp = 1 + helper(s, k+1, j);
                res = min(res, temp);
            }
            
        }
        
        return t[i][j] = res;
        
    }
    
    int palindromicPartition(string &s) {
        
        int n = s.length();
        
        memset(t, -1, sizeof(t));
        
        return helper(s, 0, n - 1);
    }
};