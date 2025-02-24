class Solution {
public:
    int fact(int n){

        if(n == 0)
            return 1;

        return n * fact(n-1);
    }

    string helper(int soFar, int n, int k, string out, vector<bool>& visited){

        if(n == 0)
            return out;

        for(int i=1;i <= n + out.size();i++){

            if(!visited[i-1]){
                if(soFar + fact(n-1) >= k){
                    visited[i-1] = true;
                    out.push_back('0' + i);
                    
                    return helper(soFar, n-1, k, out, visited);
                }

                else if(!visited[i-1])
                    soFar += fact(n-1);
            }

        }
        
        return "placeholder";
    }

    string getPermutation(int n, int k) {

        vector<bool> visited (n, false);
        string res = helper(0, n, k, "", visited);

        return res;

    }
};