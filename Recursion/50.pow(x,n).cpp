class Solution {
public:
    double myPow(double x, int n) {
        
        if(x == 1 || n == 0){
            return 1;
        }

        // when n = INT_MIN, then -n overflows "int" boundaries
        bool flag = false;
        if(n < 0){
            flag = true;
            
            if(n <= INT_MIN){
                x *= x;
                n /= 2;
            }
            n = -n;
        }

        double res;
        
        if(n&1)
            res = x * myPow(x, n-1);
        else
            res =  myPow(x*x, n/2);

        if(flag)
            return 1/res;
        
        return res;

    }
};