#include <iostream>

using namespace std;

stack<int> reverseAStack(stack<int> st, stack<int> temp){

    if(st.empty()){
        return temp;
    }

    int ele = st.top();
    st.pop();

    temp.push(ele);

    return reverseAStack(st, temp);

}

void print(stack<int> st){

    if(st.empty())
        return;

    int ele = st.top();
    st.pop();
    
    print(st);

    cout << ele << " ";

}

int main(){
    
    int n, ele;
    cin >> n;

    stack<int> st;

    for(int i=0;i<n;i++){

        cin >> ele;
        st.push(ele);

    }

    stack<int> temp;

    st = reverseAStack(st, temp);

    print(st);

    return 0;
}