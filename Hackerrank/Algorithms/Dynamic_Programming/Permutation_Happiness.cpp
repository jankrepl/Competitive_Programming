// Name: Permutation_Happiness
// WWWW: https://www.hackerrank.com/contests/world-codesprint-10/challenges/permutation-happiness
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
#include <tuple>
#include <typeinfo>
#include <cstring> 
using namespace std;




                          /* Strategy */
// We will focus on the number of UNHAPPY people instead of the number of happy people
// Its clear.. that #_happy = n - #_unhappy
//
// FACT 1 : Adding a new person to the line will either keep the number of unhappy people the same or will make it bigger by 1
// 
// FACT 2 : There are never 2 unhappy people next to each otther
// Main recursive relationship: sol(n,k) = sol(n - 1, k)(2*k) + sol(n - 1, k - 1)(n - 2*(k - 1))
    // Explanation:
// EXPRESSION ONE:  If we put a new person next to a unhappy person ..we will make the unhappy happy and the new unhappy
// -> fact 2 suggest the new person can be put to both left and right of the unhappy -> 2*k positions
// EXPRESSION TWO: Per above..all the other positions will just cause the new person to be unhappy and wont
// change the mood of the poeple in the line already

const int p = 1000000007;
const int n_max = 3001;

unsigned long memo_table[n_max][n_max]; // dont need to populate all values...k > n doesnt make sense anyway

void generate_memo(){
  // known values 
  memset(memo_table, 0, sizeof(memo_table));
  memo_table[1][0] = 0;
  memo_table[1][1] = 1;
  memo_table[2][0] = 0;
  memo_table[2][1] = 1;
  memo_table[2][2] = 0;

  // bottow up DP -> result(n,k) = f(result(n - 1, k), result(n - 1, k - 1))
  // thiking about it graphically,

  //k = 0 1 2 3 4 5 
  //    0 0 0 0 0 0  n = 0                    
  //    _ _ 0 0 0 0  n = 1
  //    _ _ _ 0 0 0  n = 2 
  //    _ _ _ _ 0 0  n = 3   
  //    _ _ _ _ _ 0  n = 4     
  //    _ _ _ _ _ _  n = 5       
  for(int n = 2; n < n_max; n++){
    for(int k = 1; k < n_max; k++){
      

      memo_table[n][k] = ( memo_table[n - 1][k] * (2 * k) + memo_table[n - 1][k - 1] * (n - 2*(k - 1))) % p;


    }
  }
}


int main(){
  generate_memo();
  int t, n, k;
  cin >> t;
  while(t--){
    // if we want k or more happy people..that means we want n - k and less unhappy people
    cin >> n >> k;
    unsigned long result = 0;
    for(int i = 0; i <= n - k; i++){
        result = (result + memo_table[n][i]) % p;
    }
    cout << result << endl;
  }

}