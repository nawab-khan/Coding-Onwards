class Solution {
public:
    int minimumLength(string s) {
        
        vector<int> freq (26,0);

        int n = s.length(), res = 0;

        for(int i=0;i<n;i++)
            freq[s[i] - 'a']++;

        for(int i=0;i<26;i++){

            if(freq[i]&1){                
                res += 1;
            }
            else{
                res += (freq[i] ? 2 : 0); 
            }

        }

        return res;
    }
};