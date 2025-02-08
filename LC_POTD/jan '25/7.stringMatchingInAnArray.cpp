class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.length(), temp = 0, count = 0;
        vector<int> prefix (n,0);
        vector<int> suffix (n,0);
        vector<int> res (n,0);

        for(int i=0;i<n;i++){

            temp += count;
            prefix[i] = temp;

            if(boxes[i] == '1')
                count++;

        }

        temp = 0, count = 0;

        for(int i=n-1;i>=0;i--){

            temp += count;
            suffix[i] = temp;

            if(boxes[i] == '1')
                count++;

        }

        for(int i=0;i<n;i++)
            res[i] = suffix[i] + prefix[i];


        return res;
    }
};