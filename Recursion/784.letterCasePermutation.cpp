class Solution {
public:
    void permute(string& str, int s, string out, vector<string>& res){

        if(s == str.length()){
            res.insert(res.begin(), out);
            return;
        }

        if(str[s] >= '0' && str[s] <= '9'){
            permute(str, s + 1, out + str[s], res);
        }
        else{
            permute(str, s + 1, out + str[s], res);
        
            char temp;

            if(str[s] < 91)
                temp = (str[s] + 32);
            else
                temp = (str[s] - 32);

            permute(str, s + 1, out + temp, res);

        }
    }

    vector<string> letterCasePermutation(string str) {
        
        vector<string> res;

        permute(str, 0, "", res);

        return res;
    }
};