#include <iostream>
using namespace std;

bool checker(int c, int ele, vector<int>& colors, vector<vector<int>>& vert){
     
    for(int i=0;i<vert[ele].size();i++)
        if(c == colors[ vert[ele][i] ])
            return false;
    
    return true;
}

bool helper(int& v, int s, vector<int>& colors, vector<vector<int>>& vert, int& m){

    if(s == v)
        return true;
    
    for(int i=0;i<m;i++){
        
        if(checker(i, s, colors, vert))
            colors[s] = i;
        else
            continue;
            
        if(helper(v, s + 1, colors, vert, m))
            return true;
        
        colors[s] = -1;
    }
    
    return false;
}
  
bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
    
    vector<int> temp;
    vector<vector<int>> vert (v, temp);
    
    for(int i=0;i<edges.size();i++){
        vert[edges[i].first].push_back(edges[i].second);
        vert[edges[i].second].push_back(edges[i].first);
    }
    
    for(int i=0;i<v;i++)
        temp.push_back(-1);
    
    return helper(v, 0, temp, vert, m);
}

int main(){

    int v, e;
    cin >> v >> e;

    vector<pair<int, int> > edges;

    for(int i=0;i<e;i++){
        
        int a, b;
        cin >> a >> b;

        edges.push_back(make_pair(a, b));

    }

    int m;
    cin >> m;

    cout << graphColoring(v, edges, m);
 
    return 0;
}