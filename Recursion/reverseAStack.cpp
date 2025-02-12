#include <iostream>

using namespace std;

void insert(stack<int>& st, int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int val = st.top();
    st.pop();

    insert(st, ele);

    st.push(val);

}

void reverseAStack(stack<int>& st){

    if(st.empty())
        return;
    
    int ele = st.top();
    st.pop();

    reverseAStack(st);

    insert(st, ele);

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

    reverseAStack(st);

    print(st);

    return 0;
}