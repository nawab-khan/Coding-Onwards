class Solution {
public:
    bool isPowerOfFour(int n) {
        
        bool flag = false;

        if(n <=0 || n%4)
            return (n == 1);

        double logd = log(n)/log(4);

        return (logd == floor(logd));

    }
};