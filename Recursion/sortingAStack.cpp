#include <iostream>

using namespace std;

void insert(stack<int>& st, int ele){

    if(st.empty() || st.top() < ele){
        st.push(ele);
        return;
    }

    int val = st.top();
    st.pop();

    insert(st, ele);

    st.push(val);

}

void sortingAStack(stack<int>& st){

    if(st.empty())
        return;
    
    int ele = st.top();

    st.pop();

    sortingAStack(st);

    insert(st, ele);

}

int main(){
    
    stack<int> st;

    int n, ele;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> ele;
        st.push(ele);
    }
    
    stack<int> temp = st;

    cout << endl;

    while(!temp.empty()){

        cout << temp.top() << " ";
        temp.pop();

    }

    cout << endl;

    // Sorting
    sortingAStack(st);

    temp = st;

    while(!temp.empty()){

        cout << temp.top() << " ";
        temp.pop();

    }

    return 0;
}