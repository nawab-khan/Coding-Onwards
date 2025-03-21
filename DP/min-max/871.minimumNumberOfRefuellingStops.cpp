int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
    int n = stations.size();

    vector<long> t(n + 1, 0);

    t[0] = startFuel;

    for(int i=0;i<n;i++){

        for(int j=i;j>=0;j--){

            if(t[j] >= stations[i][0]){
                t[j+1] = max(t[j+1], t[j] + (long) stations[i][1]);
            }

        }

    }

    for(int i=0;i<=n;i++){
        if(t[i] >= target)
            return i;
    }

    return -1;
    // vector<int> temp = {0, startFuel};
    // stations.insert(stations.begin(), temp);

    // temp = {target, 0};
    // stations.push_back(temp);
    
    // int res = helper(target, startFuel, stations, 1);

    // return (res == INT_MAX - 1) ? -1 : res;
}