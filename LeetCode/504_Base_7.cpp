// Name: 504_Base_7
// WWWW: https://leetcode.com/problems/base-7
// Author: Jan Krepl

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        
        string result = "";
        bool is_negative = (num < 0);
        if(is_negative) num = -num;
        while(num > 0){
            result += char((num % 7) + 48);
            num /= 7;
        }
        reverse(result.begin(), result.end());
        return (is_negative ? "-" + result : result);
        
    }
}