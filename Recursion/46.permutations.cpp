class Solution {
public:
    void helper(vector<int> in, vector<int> out, vector<vector<int>>& res){

        if(in.empty()){
            res.push_back(out);
            return;
        }

        for(int i=0;i<in.size();i++){
            
            int ele = in[i];
            in.erase(in.begin() + i);
            out.push_back(ele);

            helper(in, out, res);

            out.pop_back();
            in.insert(in.begin() + i, ele);

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> out;

        helper(nums, out, res);

        return res;
    }
};