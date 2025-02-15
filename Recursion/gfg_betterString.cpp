#include <iostream>
#include <set>
using namespace std;

    void subs(string str, string out, set<string> &count){

        if(str.empty()){
            count.insert(out);
            return;
        }
        
        string temp = out + str[0];

        subs(str.substr(1), out, count);
        subs(str.substr(1), temp, count);

    }
    
    string betterString(string str1, string str2) {
        
        set<string> s;
        
        subs(str1, "", s);
        int x = s.size();
        
        s.clear();
        subs(str2, "", s);
        int y = s.size();

        cout << x << " " << y << endl;

        if(x < y)
            return str2;
        
        return str1;

    }

    int main(){

        string str1 = "lalcngi", str2 = "xazfgom";

        cout << betterString(str1, str2);

    }