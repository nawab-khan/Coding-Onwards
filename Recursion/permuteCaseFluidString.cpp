#include <iostream>

using namespace std;

void permute(string& str, int s, string out, vector<string>& res){

    if(s == str.length()){
        res.insert(res.begin(), out);
        return;
    }

    permute(str, s + 1, out + str[s], res);

    char temp;

    if(str[s] < 91)
        temp = (str[s] + 32);
    else
        temp = (str[s] - 32);

    permute(str, s + 1, out + temp, res);

}

int main(){
    
    string str;
    cin >> str;

    vector<string> res;

    permute(str, 0, "", res);

    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";

    return 0;
}