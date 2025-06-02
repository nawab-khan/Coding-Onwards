#include <iostream>
using namespace std;

int partition(vector<int>& vec, int l, int h){


    int pivot = vec[l], i = l - 1, j = h + 1;

    while(1){

        while(vec[i] < pivot){
            i++;
        }

        while(vec[j] > pivot){
            j--;
        }

        if(i >= j)
            return j;

        swap(vec[i], vec[j]);
    }

}

vector<int> quickSort(vector<int>& vec, int l, int h){

    if(l < h){

        int p = partition(vec, l, h);

        quickSort(vec, l, p);
        quickSort(vec, p+1, h);
        
    }

    return vec;
}

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

// 10, 3, 4, 5, 6, 20, 18