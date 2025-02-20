#include <iostream>
using namespace std;

void helper(int n, int open, string out, vector<string>& res){

    if(n == 0 && open == 0){
        res.push_back(out);
        return;
    }

    if(open == 0)
        helper(n - 1, open + 1, out + '(', res);
    else if(n == 0)
        helper(n, open - 1, out + ')', res);
    else{
        helper(n - 1, open + 1, out + '(', res);
    
        helper(n, open - 1, out + ')', res);
    }
    
}

vector<string> generateParenthesis(int A) {
    
    vector<string> res;

    helper(A, 0, "", res);

    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";

    return res;
    
}

int main(){
    
    int n;
    cin >> n;

    generateParenthesis(n);
    
    return 0;
}