class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n&1)
            return false;
        
        int count_open = 0, notLocked = 0;
        
        // Iterate through the string from left to right to handle '(' and ')'.
        for (int i = 0; i < n; i++) {

            if (locked[i] == '0') 
                notLocked++;
            
            else if (s[i] == '(') 
                count_open++;
            
            else if (s[i] == ')') {
                if (count_open > 0) 
                    count_open--;
            
                else if (notLocked > 0) 
                    notLocked--;
            
                else 
                    return false;
                
            }
        }

        // Match remaining open brackets with notLocked characters by moving right to left.
        int flag = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (locked[i] == '0') {
                flag--;
                notLocked--;
            }
            
            else if (s[i] == '(') {
                flag++;
                count_open--;
            } 
            
            else if (s[i] == ')') 
                flag--;

            if (flag > 0)
                return false;

            if (notLocked == 0 and count_open == 0)
                break;

        }

        if (count_open > 0)
            return false;

        return true;
    }
};