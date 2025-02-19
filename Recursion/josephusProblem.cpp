#include <iostream>

using namespace std;

int helper(vector<int>& jews, int s, int k){

    int n = jews.size();

    if(n == 1){
        return jews[0];
    }

    int deadGuy = (s + k)%n;
    
    jews.erase(jews.begin() + deadGuy);
    
    return helper(jews, deadGuy, k);
}

int safePos(int n, int k) {
    
    vector<int> jews (n,0);

    for(int i = 1;i <= n;i++)
        jews[i - 1] = i;
    
    return helper(jews, 0, k - 1);    
    
}

int main(){
    
    int n, k;
    cin >> n >> k;

    cout << safePos(n, k); 
    
    return 0;
}