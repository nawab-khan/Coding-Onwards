#include <iostream>
using namespace std;

int partition(vector<int>& vec, int l, int h){

    int pivot = vec[h];
    int i = l - 1;

    for(int j = l;j <= h;j++){
        if(vec[j] < pivot){
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i+1], vec[h]);

    return i + 1;

}

vector<int> quickSort(vector<int>& vec, int l, int h){

    if(l < h){    
        int p = partition(vec, l, h);

        quickSort(vec, l , p - 1);
        quickSort(vec, p + 1, h);
    }

    return vec;
}

// 10, 3, 4, 5, 6, 20, 18

int main(){
    
    int n;
    cin >> n;

    vector<int> vec (n);

    for(int i=0;i<n;i++)
        cin >> vec[i];

    vec = quickSort(vec, 0 , vec.size() - 1);
    
    for(int i : vec)
        cout << i << " ";

    return 0;
}