class Solution {
public:
    void helper(int k, int target, vector<int> out, vector<vector<int>>& res){

        if(k == 0 && target == 0){
            res.push_back(out);
            return;
        }

        int index = out.empty() ? 0 : out[out.size() - 1];

        for(int i = index + 1;i <= 9;i++){

            if(i > target)
                break;
            
            out.push_back(i);
            helper(k - 1, target - i, out, res);
            
            out.pop_back();

        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;
        vector<int> out;

        helper(k, n, out, res);

        return res;
    }
};