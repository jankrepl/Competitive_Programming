// Name: 217_Contains_Duplicate
// WWWW: https://leetcode.com/problems/reshape-the-matrix
// Author: Jan Krepl

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> test(nums.begin(), nums.end());
        return nums.size() != test.size();
        
    }
};