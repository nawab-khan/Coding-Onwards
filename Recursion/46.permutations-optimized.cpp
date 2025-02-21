class Solution {
public:
    void helper(vector<int>& in, int index, vector<vector<int>>& res){

        if(in.size() == index){
            res.push_back(in);
            return;
        }

        for(int i=index;i<in.size();i++){
            
            swap(in[index], in[i]);

            helper(in, index + 1, res);

            swap(in[index], in[i]);

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> out;

        helper(nums, 0, res);

        return res;
    }
};