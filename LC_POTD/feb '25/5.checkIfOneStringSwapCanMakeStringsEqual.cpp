class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int n = s1.length(), count = 0, c = 0;
        vector<int> alph (26,0);

        for(int i=0;i<n;i++){

            alph[s1[i] - 'a']++, alph[s2[i] - 'a']--;

            if(s1[i] != s2[i])
                count++;

        }

        for(int i : alph)
            if(i)
                return false;

        if(count == 0 || count == 2)
            return true;
        
        return false;

    }
};