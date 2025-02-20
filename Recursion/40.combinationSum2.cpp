class Solution {
public:
    void helper(vector<int>& c, int s, int target, vector<int> out, set<vector<int>>& res){

        if(target == 0){
            res.insert(out);
            return;
        }

        // if(s >= c.size())
        //     return;

        for(int i = s; i < c.size();i++){

            if(i > s && c[i] == c[i-1])
                continue;
            
            // all greater than c[i] will also be > target
            if(c[i] > target)
                break;
            
            out.push_back(c[i]);
            helper(c, i + 1, target - c[i], out, res);

            out.pop_back();
        }

        // helper(c, s + 1, target, out, res);

        // out.push_back(c[s]);
        // helper(c, s + 1, target - c[s], out, res);

    }

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        
        sort(c.begin(), c.end());

        set<vector<int>> temp;
        vector<int> out;

        helper(c, 0, target, out, temp);

        vector<vector<int>> res;

        for(auto it = temp.begin(); it != temp.end(); it++){
            res.push_back(*it);
        }

        return res;
    }
};