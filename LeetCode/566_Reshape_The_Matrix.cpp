// Name: 566_Reshape_The_Matrix
// WWWW: https://leetcode.com/problems/reshape-the-matrix
// Author: Jan Krepl

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        
        vector<vector<int>> output(r,vector<int>(c,0));
        int r_old = nums.size();
        int c_old = nums[0].size();      
        
        // check if legal
        if(r_old * c_old != r * c){
            return nums;
        }
        
        // flatten old array
        vector<int> flattened(r_old*c_old);
        
        for(int i = 0; i < r_old; i++){
            for(int j = 0; j < c_old; j++){
                flattened[i*c_old +j] = nums[i][j]; 
            }
        }    
            
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                output[i][j] = flattened[i*c + j];
            }
        }
        return output;
    }
};