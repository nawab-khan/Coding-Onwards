class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int n = s1.length(), m = s2.length(), i, j;

        vector<vector<int>> t(n+1, vector<int> (m+1));
        
        for(i=0;i<n+1;i++){
            for(j=0;j<m+1;j++){

                if(i == 0||j == 0){
                    t[i][j] = 0;
                    continue;
                }

                if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);

            }

            
        }

        string str;

        i--, j--;
        while(i && j){

            if(s1[i-1] == s2[j-1]){
                str.push_back(s1[i-1]);
                i--, j--;
            }
            else if(t[i-1][j] > t[i][j-1]){
                str.push_back(s1[i-1]);
                i--;
            }
            else{
                str.push_back(s2[j-1]);
                j--;
            }

        }

        while(i--){
            str.push_back(s1[i]);
        }

        while(j--){
            str.push_back(s2[j]);
        }

        reverse(str.begin(), str.end());

        return str;
    }
};