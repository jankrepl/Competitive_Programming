// Name: 461_Hamming_Distance
// WWWW: https://leetcode.com/problems/hamming-distance
// Author: Jan Krepl

class Solution {
public:
    int hammingDistance(int x, int y) {
        int counter = 0;
        
        while(x > 0 || y > 0){
            if((x % 2 == 0 && y % 2 == 1) || (x % 2 == 1 && y % 2 == 0)){
                counter++;
                
            }
            x /= 2;
            y /= 2;
        }
        return counter;
    }
};