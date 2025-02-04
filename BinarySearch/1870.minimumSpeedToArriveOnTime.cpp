class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int n = dist.size(), l = 1, r = 1e9, m, res = -1;
        double totalTime;

        while(l <= r){

            int m = l + (r - l)/2;
            totalTime = 0;

            for(int i=0;i<n-1;i++){
                totalTime += ceil(dist[i]/((double) m));
            }
            
            totalTime += dist[n-1]/((double) m);

            if(totalTime <= hour){
                r = m - 1;
                res = m;
            }
            else
                l = m + 1;

        }
        return res;
    }
};