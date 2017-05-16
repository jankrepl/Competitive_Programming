// Name: 560_Subarray_Sum_Equals_K
// WWWW: https://leetcode.com/problems/subarray-sum-equals-k
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

/* Solution 1*/
// brute force
// O(N^2)

class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
      /* Strategy */
      // Create a partial sum array..and then do brute force 
      int size = nums.size();
      vector<int> ps_nums(size + 1);
      partial_sum(nums.begin(), nums.end(), ps_nums.begin());


      long counter = 0;
      for(int len = 1; len <= size ; len++){
       for(int start = 0; start < size - len; start++){
        if(len == 1 && nums[start] == k){
          counter++;
          continue;
        }

        if(start == 0 && ps_nums[start + len - 1] == k){
          counter++;
          continue;
        }

        if(ps_nums[start + len - 1] - ps_nums[start - 1] == k){
          counter++;
          continue;

        }

        }

       } 
       return counter;

      }

};


/* Solution 2*/
// CLEVER
// O(N)

/* Strategy */
// we traverse through nums and keep account of the partial sum up to a current position
// At each iteration we save this sum into a map<int,int> as a key..and value will be the number of times this sum has appeared so far
// the solution can be simply deduced then...because a solution (contingent subarray) that has an ending at index i, the cumsum[i] - k must
// be in our map already...if more than once..we found more than 1 solution

class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cumsum = 0; // cumulated sum
        map<int,int> memo; // prefix sum recorder
        int counter = 0; // number of found subarray
        memo[0]++; // zero some occured once:))
        for(int i = 0; i < nums.size(); i++){
            cumsum += nums[i];
            counter += memo[cumsum-k]; // note that if a given key doesnt exists, c++ defines it with value 0 by default
            memo[cumsum]++; // 
        }
        return counter ;
    }

};


