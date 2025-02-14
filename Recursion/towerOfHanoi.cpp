#include <iostream>

using namespace std;

void move(int n, int src, int dest, int help, int& steps){

    steps++;

    if(n == 1){
        cout << "Moving plate from  " << src << " to " << dest << " using " << help << endl;
        return;
    }

    move(n-1, src, help, dest, steps);

    cout << "Moving plate from  " << src << " to " << dest << " using " << help << endl;

    move(n-1, help, dest, src, steps);

}

int main(){
    
    int n, steps = 0;
    cin >> n;

    int src = 1, dest = 2, help = 3;

    move(n, src, dest, help, steps);
    
    cout << "Took " << steps << " steps";
    
    return 0;
}