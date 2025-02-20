#include <iostream>
using namespace std;

void helper(int n, int diff, string out, vector<string>& res){

    if(n ==0){
        // required in order of decreasing magnitude
        res.insert(res.begin(), out);
        return;
    }

    if(diff){
        helper(n - 1, diff - 1, out + '0', res);

        helper(n - 1, diff + 1, out + '1', res);
    }
    else{
        helper(n - 1, diff + 1, out + '1', res);
    }

}

vector<string> NBitBinary(int n){
    
    vector<string> res;

    helper(n - 1, 1, "1", res);

    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";

    return res;

}

int main(){
    
    int n;
    cin >> n;

    NBitBinary(n);
    
    return 0;
}