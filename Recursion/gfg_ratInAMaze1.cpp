#include <iostream>
using namespace std;

void helperCompact(int row, int col, vector<vector<int>> &mat, string out, vector<string>& res, vector<vector<bool>>& visited, vector<int> dirI, vector<int> dirJ){
        
    if(row == mat.size()-1 && col == mat.size()-1){
        res.push_back(out);
        return;
    }

    //check all directions in a compact way

    string direction = "DLRU";

    for (int ind = 0; ind < 4; ind++) {
      int nextrow= row+ dirI[ind];
      int nextcol= col+ dirJ[ind];
      if (nextrow>= 0 && nextcol>= 0 && nextrow< mat.size() && nextcol< mat.size() && !visited[nextrow][nextcol] && mat[nextrow][nextcol] == 1) {
        visited[row][col] = 1;
        helperCompact(nextrow, nextcol, mat, out + direction[ind], res, visited, dirI, dirJ);
        visited[row][col] = 0;
      }
    }
    
}

// void helper(int& n, int row, int col, vector<vector<int>> &mat, string& out, vector<string>& res, vector<vector<bool>>& visited){
        
//     if(row == n-1 && col == n-1){
//         res.push_back(out);
//         return;
//     }

//     // lexicographical order (D L R U)
    
//     //D
//     if(row + 1 < n && mat[row+1][col] && !visited[row][col]){
//         visited[row][col] = true;
//         out.push_back('D');
//         helper(n, row + 1, col, mat, out, res, visited);
//         out.pop_back();
//         visited[row][col] = false;
//     }
    
//     //L
//     if(col - 1 >= 0 && mat[row][col-1] && !visited[row][col]){
//         visited[row][col] = true;
//         out.push_back('L');
//         helper(n, row, col - 1, mat, out, res, visited);
//         out.pop_back();
//         visited[row][col] = false;
//     }
    
//     //R
//     if(col + 1 < n && mat[row][col+1] && !visited[row][col]){
//         visited[row][col] = true;
//         out.push_back('R');
//         helper(n, row, col + 1, mat, out, res, visited);
//         out.pop_back();
//         visited[row][col] = false;
//     }

//     //U
//     if(row - 1 >= 0 && mat[row-1][col] && !visited[row][col]){
//         visited[row][col] = true;
//         out.push_back('U');
//         helper(n, row - 1, col, mat, out, res, visited);
//         out.pop_back();
//         visited[row][col] = false;
//     }

// }

vector<string> findPath(vector<vector<int>> &mat) {
    
    int n = mat.size();
    vector<string> res;
    
    if(mat[0][0] == 0 && mat[n-1][n-1] == 0)
        return res;
    
    vector<bool> temp (n, false);
    vector<vector<bool>> visited (n, temp);

    string out = "";

    // helper(n, 0, 0, mat, "", res, visited);


    vector<int> dirI = {
        +1,
        0,
        0,
        -1
      };
      vector<int> dirJ = {
        0,
        -1,
        1,
        0
      };

      helperCompact(0, 0, mat, out, res, visited, dirI, dirJ);

    return res;
}