// Name: Cavity_Map
// WWWW: https://www.hackerrank.com/challenges/cavity-map
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    vector<int> empty(n,0);
    vector<vector<int>> matrix(n,empty);

    for(int grid_i = 0;grid_i < n;grid_i++){
        cin >> grid[grid_i];
        for(int i = 0; i < n; i++){
            matrix[grid_i][i] = int((grid[grid_i])[i])-48;
        }
    }
    vector<vector<int>> result = matrix;


    for(int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if(matrix[i][j] > matrix[i + 1][j] && matrix[i][j] > matrix[i - 1][j] && matrix[i][j] > matrix[i][j - 1] && matrix[i][j] > matrix[i][j + 1]){
                result[i][j] = -1; 
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(result[i][j] == -1){
                cout << "X";
            }else{
                cout << result[i][j];
                    
            };
        }
        cout << endl;
    }
    return 0;
}
