#include <iostream>
#include <string>
using namespace std;

void helper(string& str, int s, string out, vector<string>& res){

    if(s == str.length()){
        res.push_back(out);
        return;
    }

    helper(str, s + 1, out + str[s], res);
    if(s < str.length() - 1)
        helper(str, s + 1, out + str[s] + " ", res);

}

vector<string> permutation(string str) {
        
    int n = str.length();

    vector<string> res;
    helper(str, 0, "", res);

    sort(res.begin(), res.end());

    for(auto i : res)
        cout << i << endl;

    return res;

}