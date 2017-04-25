// Name: 561_Array_Partition_I
// WWWW: https://leetcode.com/problems/array-partition-i
// Author: Jan Krepl

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        /* Strategy */
        // Sort the vector and then just even-indexed elements
        int output = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
    
    
        for(int i = 0; i < size/2; i++){
            output += nums[2*i];
        } 
        return output;
    
    }
};