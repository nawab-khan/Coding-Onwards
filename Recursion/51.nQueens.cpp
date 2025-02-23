class Solution {
public:
    //to check if position is safe
    bool checker(int& n, int col, string row, vector<string> out){

        if(out.empty())
            return true;

        int size = out.size();
        int r = size, diag;

        for(int i = 0;i < size;i++){
            
            if(out[i][col] == 'Q')
                return false;

            diag = abs(i - r);

            if(col - diag >= 0 && out[i][col - diag] == 'Q')
                return false;

            if(col + diag <= n && out[i][col + diag] == 'Q')
                return false;

        }

        return true;
    }

    void helper(int& n, int count, vector<string> out, vector<vector<string>>& res){

        //bc
        if(count == n){
            res.push_back(out);
            return;
        }

        for(int i=0;i<n;i++){

            string row (n, '.');
            row[i] = 'Q';
            
            if(checker(n, i, row, out))
                out.push_back(row);
            else
                continue;

            helper(n, count + 1, out, res);

            out.pop_back(); 

        }

    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> out;

        helper(n, 0, out, res);

        return res;
    }
};