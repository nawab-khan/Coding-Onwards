class Solution {
public:
    // char builder(string str, int n, int k){
        
    //     if(n == 0)
    //         return str[k - 1];
        
    //     string temp = "";

    //     int l = str.length();

    //     for(int i=0;i<l;i++){
    //         if(str[i] == '0')
    //             temp = temp + "01";
    //         else
    //             temp = temp + "10";
    //     }

    //     str = temp;

    //     return builder(str, n - 1, k);

    // }

    int kthGrammar(int n, int k) {

        if(k == 1){
            return 0;
        }

        if(k&1)
            return kthGrammar(n - 1, (k + 1)/2);
        else
            return 1 - kthGrammar(n - 1, k/2);

        // if(kthGrammar(n - 1, k/2) == 0){

        //     if(k&1)
        //         return 0;
        //     else
        //         return 1;

        // }
        // else{

        //     if(k&1)
        //         return 1;
        //     else
        //         return 0;

        // }

    }
};