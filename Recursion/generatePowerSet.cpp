#include <iostream>

using namespace std;

vector<string> out;

void generatePowerSet(string charsin, string charsout){
    
    if(charsin.empty()){
        out.push_back(charsout);
        return;
    }

    string temp = charsout + charsin[0];

    generatePowerSet(charsin.substr(1), charsout);

    generatePowerSet(charsin.substr(1), temp);

}

int main(){

    int n;
    cin >> n;
    
    string chars (n,'*');
    for(int i=0;i<n;i++)
        cin >> chars[i];

    generatePowerSet(chars, "");

    for(auto i : out){
        string a = i.empty() ? "*" : i;
        cout << a <<  " ";
    }
    
    return 0;
}