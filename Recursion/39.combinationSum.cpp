class Solution {
public:

    void helper(vector<int>& c, int s, int target, vector<int> out, set<vector<int>>& res){

        if(target == 0){
            res.insert(out);
            return;
        }

        if(target < 0 || s == c.size()){
            return;
        }

        helper(c, s + 1, target, out, res);

        out.push_back(c[s]);

        helper(c, s, target - c[s], out, res);

        helper(c, s + 1, target - c[s], out, res);


    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        
        int n = c.size();

        set<vector<int>> res;
        vector<int> out;

        helper(c, 0, target, out, res);

        vector<vector<int>> temp;

        for(auto it = res.begin();it != res.end(); it++){
            temp.push_back(*it);
        }

        return temp;
    }
};