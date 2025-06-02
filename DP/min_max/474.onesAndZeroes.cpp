//    m    n    index
int t[101][101][601];

// t[m][n][l] : maximum length of subset that follows the rules (atmost m 0's and n 1's) from  index 0 to l̀

int helper(int m, int n, vector<int>& zer, vector<int>& one, int l){

    if(l == 0){
        return 0;
    }

    if(t[m][n][l] != -1)
        return t[m][n][l];

    if(zer[l - 1] > m || one[l-1] > n){
        return helper(m, n, zer, one, l-1);
    }
    
    return t[m][n][l] = max(helper(m, n, zer, one, l-1), 1 + helper(m - zer[l-1], n - one[l-1], zer, one, l-1));

}

int findMaxForm(vector<string>& str, int m, int n) {
    
    int l = str.size();

    vector<int> zer (l, 0);
    vector<int> one (l, 0);

    for(int i=0;i<l;i++){

        int o = 0, z = 0, j = 0;

        while(j < str[i].length()){

            if(str[i][j] == '0')
                z++;
            else
                o++;
            
            j++;

        }

        zer[i] = z;
        one[i] = o;

    }

    memset(t, -1, sizeof(t));

    int res = helper(m, n, zer, one, l);

    return (res < 0) ? 0 : res; 
}