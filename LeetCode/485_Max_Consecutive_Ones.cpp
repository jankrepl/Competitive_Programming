// Name: 485_Max_Consecutive_Ones
// WWWW: https://leetcode.com/problems/max-consecutive-ones/#/description
// Author: Jan Krepl

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int global_sol = 0;
        int longest_streak = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                longest_streak++;
            }else{
                longest_streak = 0;
            }
            global_sol = max(global_sol,longest_streak);
            
        }
        return global_sol;
        
    }
};