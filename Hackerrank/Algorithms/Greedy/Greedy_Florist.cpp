// Name: Greedy_Florist
// WWWW: https://www.hackerrank.com/challenges/greedy-florist
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


// Strategy
  // 0 step - sort from most expensive to cheapest
  // 1 step - each person buys the most expensive flower
  // 2 step - update prices
  // do until no flowers left


int main(){
  int N, K;
  cin >> N >> K;
  vector<int> prices(N);
  for(int i = 0; i < N; i++) cin >> prices[i];

  // Step 0  
  sort(prices.rbegin(), prices.rend());
  vector<int> updated_prices = prices;

  // Initialize variables
  int n_purchases = 0; // The total number of purchases in the grouu
  int flower_index = 0;
  int ans = 0;


  while(true){
    // Step 1

    for(int i = 0; i < K; i++){
      ans += updated_prices[flower_index];
      flower_index++;
      n_purchases++;
      if(flower_index == N){
        goto jump;
      }

    }

    // Step 2
    for(int i = flower_index; i < N; i++){
      updated_prices[i] =  prices[i] * ((n_purchases / K) + 1);
    }

  }
  jump:;

  cout << ans << endl;

}