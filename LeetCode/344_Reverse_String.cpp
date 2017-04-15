// Name: 344_Reverse_String
// WWWW: https://leetcode.com/problems/reverse-string
// Author: Jan Krepl

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};