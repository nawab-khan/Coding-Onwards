class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if(s.length() < k)
            return false;

        vector<int> freq (26,0);
        int n = s.length(), count_odds = 0;

        for(int i=0;i<n;i++)
            freq[s[i] - 'a']++;


        for(int i=0;i<26;i++)
            if(freq[i]&1)
                count_odds++;

        if(count_odds > k)
            return false;

        return true;

    }
};