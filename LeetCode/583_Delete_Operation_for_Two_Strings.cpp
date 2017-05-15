// Name: 583_Delete_Operation_for_Two_Strings
// WWWW: https://leetcode.com/problems/delete-operation-for-two-strings
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <assert.h>
#include <cstring>
#include <typeinfo>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;

/* Strategy */
// Find longest common subsequence and then count unnecessary charactercs -> size_1 + size_2 - 2*lcss.size()

  // Finding longest substring - DYNAMIC PROGRAMMING BOTTOM UP
  // dp[i][j] = solution for first i char in word_1 and first j characters in word_2
  // dp[i][0] = dp[0][j] = empty string can only have zero sized substrings:)
  
  // dp[word1.size(), word2.size()] is the solution we are looking for

  // RECURSIVE RELATIONSHIP
  // if(word_1[i] == word_2[j]){ dj[i][j] = dp[i - 1][j - 1] + 1} else{dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])}
  // 
  // filling pattern..if condition true...digonally down...if false...north or west ...
  // therefore standard standard matrix filling - up down, left right will workout



class Solution {
public:
    int minDistance(string word1, string word2) {
      int size_1 = word1.size();
      int size_2 = word2.size();

      // initialize DP memo
      vector<vector<int>> dp(size_1 + 1,vector<int>(size_2 + 1,0));

      // start populating

      for(int i = 0; i <= size_1; i++){
        for(int j = 0; j <= size_2; j++){
          if(i * j == 0){
            // :D one of them is zero
            dp[i][j] = 0;
            continue;
          }
          // just take into account c++ 0 indexing
          if(word1[i - 1] == word2[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
          }else{
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }    
    }
    return size_1 + size_2 - 2*dp[size_1][size_2];
  }
};
