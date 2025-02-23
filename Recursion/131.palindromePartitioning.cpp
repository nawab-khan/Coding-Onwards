bool checker(string str){

    int l = str.length();

    for(int i=0;i<l/2;i++)
        if(str[i] != str[l-1-i])
            return false;

    return true;
}

void helper(string& str, int s, vector<string> out, vector<vector<string>>& res){

    if(s == str.length()){
        res.push_back(out);
        return;
    }

    for(int i = 1; i <= str.length() - s;i++){

        string temp = str.substr(s, i);

        if(checker(temp)){
            out.push_back(temp);
            helper(str, s + i, out, res);

            out.pop_back();
        }


    }

}

vector<vector<string>> partition(string str) {

    vector<vector<string>> res;
    vector<string> out;

    helper(str, 0, out, res);
    
    return res;
}