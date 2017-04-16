// Name: 463_Island_Perimeter
// WWWW: https://leetcode.com/problems/island-perimeter
// Author: Jan Krepl

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        int n_columns = grid[0].size();
        vector<vector<int>> grid_helper = grid;
        for(int i = 0; i < n_rows; i++){
            for(int j = 0; j < n_columns; j++){
                grid_helper[i][j] *= 4;
            }
        }
    
        for(int i = 0; i < n_rows; i++){
            for(int j = 0; j < n_columns; j++){
                //only consider nonsea
                if(grid[i][j] != 1){
                    continue;
                }
                //above
                if(i != 0 && grid[i][j] == grid[i - 1][j] == 1){
                    grid_helper[i][j] -= 1;
                }
                //below
                if(i != n_rows - 1 && grid[i][j] == grid[i + 1][j] == 1){
                    grid_helper[i][j] -= 1;
                }
                
                //to_the_left
                if(j != 0 && grid[i][j] == grid[i][j - 1] == 1){
                    grid_helper[i][j] -= 1;
                }
                
                //to_the_right
                if(j != n_columns - 1 && grid[i][j] == grid[i][j + 1] == 1){
                    grid_helper[i][j] -= 1;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < n_rows; i++){
            for(int j = 0; j < n_columns; j++){
                result += grid_helper[i][j];
            }
        }
        return result;
    }
        
};