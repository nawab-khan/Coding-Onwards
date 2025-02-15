#include <iostream>
#include <set>
using namespace std;

set<string> out;

void generateUniqueSubsets(string charsin, string charsout){

    if(charsin.empty()){
        out.insert(charsout);
        return;
    }

    string temp = charsout + charsin[0];

    // skips the first character from input and doesnt carry it to the output
    generateUniqueSubsets(charsin.substr(1), charsout);
    
    // skips the first character from input and carries it to the output
    generateUniqueSubsets(charsin.substr(1), temp);

}

int main(){

    int n;
    cin >> n;
    
    string chars (n,'*');
    for(int i=0;i<n;i++)
        cin >> chars[i];

    generateUniqueSubsets(chars, "");

    for(auto i : out){
        string a = i.empty() ? "*" : i;
        cout << a <<  ", ";
    }
    
    return 0;
}
