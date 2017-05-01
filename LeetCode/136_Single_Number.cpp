// Name: 136_Single_Number
// WWWW: https://leetcode.com/problems/single-number
// Author: Jan Krepl

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // x ^ x = 0
        // x ^ 0 = x
        // XOR is commutative
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
};