#include <iostream>
using namespace std;

void merge(vector<int>& vec, int l, int m, int h){

    vector<int> res (h - l + 1);

    int i = l, j = m+1, k = 0;

    while(i <= m && j <= h){

        if(vec[i] <= vec[j])
            res[k++] = vec[i++];
        else
            res[k++] = vec[j++];
    }

    while(i <= m){
        res[k++] = vec[i++];
    }

    while(j <= h){
        res[k++] = vec[j++];
    }

    for(int i=l;i<=h;i++)
        vec[i] = res[i-l];

    // return vec;

} 

void mergeSort(vector<int>& vec, int l, int h){

    if(l < h){

        int m = (l + h)/2;

        mergeSort(vec, l, m);
        mergeSort(vec, m+1, h);

        merge(vec, l, m, h);

    }

    // return
}



int main(){
    
    int n;
    cin >> n;

    vector<int> vec (n);

    for(int i=0;i<n;i++)
        cin >> vec[i];

    mergeSort(vec, 0 , vec.size() - 1);
    
    for(int i : vec)
        cout << i << " ";

    return 0;
}

// 10, 3, 4, 5, 6, 20, 18