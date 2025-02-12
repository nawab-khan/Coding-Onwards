#include <iostream>

using namespace std;

// int findLength(stack<int> st){

//     if(st.empty())
//         return 0;
    
//     st.pop();
    
//     return 1 + findLength(st);
// }

void deleteMiddleElement(stack<int>& st, int n, int m){

    if(m == n/2){
        st.pop();
        return;
    }
    
    m++;

    int val = st.top();
    st.pop();

    deleteMiddleElement(st, n, m);

    st.push(val);
    
    return;

}

int main(){
    
    stack<int> st;

    int n, ele, m = 0;
    cin >> n;

    for(int i=0;i<n;i++){

        cin >> ele;
        st.push(ele);

    }

    // int len =  findLength(st);
    // deleteMiddleElement(st, len);

    deleteMiddleElement(st, n, m);

    stack<int> temp = st;

    cout << endl;
    while(!temp.empty()){

        cout << temp.top() << " ";
        temp.pop();

    }
    
    return 0;
}