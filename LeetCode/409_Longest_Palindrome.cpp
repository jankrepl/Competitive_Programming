// Name: 409_Longest_Palindrome
// WWWW: https://leetcode.com/problems/longest-palindrome
// Author: Jan Krepl


class Solution {
public:
    int longestPalindrome(string s) {
        // create histogram and count all even occurances and multiply by size
        vector<int> hist_lc(26,0);
        vector<int> hist_uc(26,0);
        
        for(int i = 0; i < s.size(); i++){
            if(isupper(s[i])){
                hist_uc[int(s[i])-65]++;
                
            }else{
                hist_lc[int(s[i])-97]++;                
                
            }
        }
        
        int counter = 0;
        for(int i = 0; i < 26; i++){
            if(hist_lc[i] % 2 == 0){
                counter += hist_lc[i];
                
            }else{
                counter += hist_lc[i] - 1;
                
            }
            if(hist_uc[i] % 2 == 0){
                counter += hist_uc[i];
                
            }else{
                counter += hist_uc[i] - 1;
            }          
        }
       return (counter == s.size() ? counter : counter + 1 ); // we can always put one in the middle:D if we have characters left 
    }
};