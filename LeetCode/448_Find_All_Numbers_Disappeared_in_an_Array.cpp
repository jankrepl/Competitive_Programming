// Name: Find_All_Numbers_Disappeared_in_an_Array
// Problem_Code: 448
// WWW: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Author: Jan Krepl

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = int(nums.size());
        vector<int> output;
        vector<bool> logger(size + 1, false);
        for(int i = 0; i < size; i++){
        logger[nums[i]] = true;
        }
        for(int i = 1; i <= size; i++){
            if(!logger[i]){
                output.push_back(i);
            }
        }
        return output;
    }
};