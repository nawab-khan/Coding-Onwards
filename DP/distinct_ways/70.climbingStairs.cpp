class Solution {
public:
    int climbStairs(int n) {
        
        int t[n+1];

        for(int i=0;i<=n;i++){
            
            if(i <= 1){
                t[i] = 1;
                continue;
            }

            t[i] = t[i-1] + t[i-2];

        }

        return t[n];
    }
};