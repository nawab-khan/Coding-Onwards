
class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.length(), temp;
        vector<int> ones, res;

        for(int i=0;i<n;i++)
            if(boxes[i] == '1')
                ones.push_back(i);

        int m = ones.size();

        for(int i=0;i<n;i++){

            temp = 0;

            for(int j=0;j<m;j++){

                if(i != ones[j]){
                    temp += abs(ones[j]-i);
                }

            }

            res.push_back(temp);

        }

        return res;
    }
};