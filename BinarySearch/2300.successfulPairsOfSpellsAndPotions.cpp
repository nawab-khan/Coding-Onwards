class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        long long score;

        vector<int> res (n,0);
        
        for(int i=0;i<n;i++){

            int l = 0, r = m - 1, mid;

            while(l <= r){
                
                mid = l + (r - l)/2;
                score = potions[mid] * (long long) spells[i];

                if(score >= success){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }

            }

            res[i] = (m - 1) - r;

        }

        return res;
    }
};