class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int n = words.size(), l = pref.length(), count = 0;

        for(int i=0;i<n;i++){

            // if(words[i].length() < l)
            //     continue;
            
            // if(checkIfPrefix(words[i], pref))
            //     count++;

            if(words[i].substr(0,l) == pref)
                count++;

        }

        return count;

    }

    // bool checkIfPrefix(string str, string sub){

    //     int n = sub.length();
    //     bool flag = true;

    //     for(int i=0;i<n;i++){

    //         if(str[i] != sub[i]){
    //             flag = false;
    //             break;
    //         }
            
    //     }

    //     return flag;

    // }

};