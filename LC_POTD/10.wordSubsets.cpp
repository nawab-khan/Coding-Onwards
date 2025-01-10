class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> res;
        int n1 = words1.size(), n2 = words2.size();

        vector<int> maxFreq (26,0);

        for(int i=0;i<n2;i++){

            vector<int> tempFreq (26,0);

            for(int j=0;j<words2[i].length();j++){

                int ele = words2[i][j] - 'a';

                tempFreq[ele]++;
                maxFreq[ele] = max(maxFreq[ele], tempFreq[ele]);

            }

        }

        for(int i=0;i<n1;i++){

            vector<int> tempFreq (26,0);
            bool flag = true;

            for(int j=0;j<words1[i].length();j++)
                tempFreq[words1[i][j] - 'a']++;

            for(int j=0;j<26;j++)
                if(maxFreq[j] > tempFreq[j]){
                    flag = false;
                    break;
                }

            if(flag)
                res.push_back(words1[i]);

        }

        return res;
    }
};