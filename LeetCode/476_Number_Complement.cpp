// Name: 476_Number_Complement
// WWWW: https://leetcode.com/problems/number-complement/
// Author: Jan Krepl

class Solution {
public:
    int findComplement(int num) {
        // Strategy - use (1,1,1,1,1,1,1,1...) and shift bits to the left as long as the trailing ones in it are 
        // alligned with the trailing zeros in num
        
        unsigned int all_ones = ~0;
        while(num & all_ones){
            all_ones <<= 1;
        }
        return ~all_ones & ~num;
    }
};