// Name: 268_Missing_Number
// WWWW: https://leetcode.com/problems/missing-number
// Author: Jan Krepl



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        //create vector
        vector<int> my_vec(size, 0);
        for(int i = 0; i < size; i++){
            my_vec[nums[i]] = 1;
        }
        return distance(my_vec.begin(), find(my_vec.begin(), my_vec.end(), 0));
    }
};