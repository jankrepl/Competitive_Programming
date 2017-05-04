// Name: Pairwise_AND_sum
// Problem_Code: AND
// WWW: https://www.codechef.com/problems/AND
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
using namespace std;


/* Strategy */
// Bitwise AND of two numbers can be written as a sum x_0 * 2^0 + x_1 * 2^1 + x_2 * 2^2 + .... + x_31 * 2^31
// x_i will be 1 iff both numbers have ith bit equal to 1 ..else x_i == 0

// This motivates the following algorithm
// STEP 1

  // Count the number of input numbers whose 0th bit is set -> c0
  // Count the number of input numbers whose 1th bit is set -> c1
  // Count the number of input numbers whose 2th bit is set -> c2
  // Count the number of input numbers whose 3th bit is set -> c3
  //...
  // Count the number of input numbers whose 31th bit is set -> c31

// STEP 2
  // long res = 2^0 * (c0 choose 2) + 2^1 * (c1 choose 2) + ... + 2^31 * (c31 choose 2) 


// HACKS
  // No need to use n choose k general function ...k is always == 2




typedef unsigned int uint;
typedef long long ll;


int main(){
  int N;
  cin >> N;
  vector<ll> counts(32,0); // ith element is how many numbers have the ith bit set

  vector<ll> numbers(N);
  for(int i = 0; i < N; i++){
      cin >> numbers[i];
      for(int j = 0; j < 32; j++){
        counts[j] += ((numbers[i] & (ll(1) << j)) >> j); // clever:)
      }
  }

  ll result = 0;

  for(int i = 0; i < 32; i++){
    // if count[i] <= 0.. it 
    result +=  ( ( ll(counts[i]) * (ll(counts[i] - ll(1))) )/ll(2) ) * (ll(1) << i); // need to cast 1 to ll..otherwise deault is int
  }

  printf("%lld\n", result);


}