// Name: Knapsack
// WWWW: https://www.hackerrank.com/challenges/unbounded-knapsack
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
// We will define a function f(array, k, memo) = minimum remaineder after taking repeatedly any elements of the array (with replacement)
// Top down approach - also help it with a memo table


  // Trick: its recursive.. f(array,k) = min (f(array, k - array[i_0]), ... , f(array, k - array[i_k]))  
  // for i_0,...,i_k such that a[i_k] <= k

  // base case ..all elements of array are bigger than k

  // als


int f(vector<int> &a, int k, vector<int> &memo){
  // try to find in memo
  if(memo[k] != -1){
    return memo[k];
  }
  // base case
  if(all_of(a.begin(), a.end(),  [&k](int i){return i > k;})){
    return memo[k] = k;
  };


  //inductive step
  int mini = numeric_limits<int>::max();
  for(int i = 0; i < a.size(); i++){
    if(a[i] <= k){
      mini = min(mini, f(a, k - a[i], memo));
    }
  }
  return memo[k] = mini;
}




int main(){
  int T;
  cin >> T;

  while(T--){
    int N, k;
    cin >> N >> k;
    vector<int> a(N);
    // create a memo table memo[i] - solution when k = i;
    vector<int> memo(k + 1, - 1);



    for(int i = 0; i < N; i++){
      cin >> a[i];
    }
    cout << k - f(a, k, memo) << endl;
  }

}
