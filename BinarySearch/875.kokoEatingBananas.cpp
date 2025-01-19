class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        long long l = 1, r = INT_MIN, m, total;

        for(int i=0;i<n;i++)
            if(r < piles[i])
                r = piles[i];

        while(l <= r){

            m = l + (r - l)/2;
            total = 0;

            for(int i=0;i<n;i++){

                total += (piles[i]/m + (piles[i]%m == 0 ? 0 : 1));

            }

            if(total > h)
                l = m + 1;
            else
                r = m - 1;
        }

        return l;
    }
};