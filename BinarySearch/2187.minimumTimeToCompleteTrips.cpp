class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        int n = time.size();
        long long l = 1, r = INT_MAX, m = 0, total = 0;

        for(int i=0;i<n;i++){
            if(time[i] < r)
            r = time[i];
        }

        r *= totalTrips;

        while(l < r){

            m = l + (r-l)/2;
            total = 0;

            for(int i=0;i<n;i++){
                total += m/time[i];

                if(total > totalTrips){
                    break;
                }
            }


            if(total >= totalTrips)
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};