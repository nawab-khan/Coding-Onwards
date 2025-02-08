class Solution {
public:
    int countPalindromicSubsequence(string str) {

        int n = str.length(), count = 0;
        set<char> s;

        for (int i = 0; i < n; i++)
            s.insert(str[i]);

        for (auto it = s.begin(); it != s.end(); it++) {

            bool flag = false;
            int f, l = 0;
            char ch = *it;

            for (int i = 0; i < n; i++) {

                if (str[i] == ch) {
                    if (!flag) {
                        f = i;
                        flag = true;
                    }

                    l = i;
                }
            }

            set<char> temp;

            for (int i = f + 1; i < l; i++)
                temp.insert(str[i]);

            count += temp.size();
        }

        return count;
    }
};