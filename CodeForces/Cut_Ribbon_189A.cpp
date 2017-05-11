// Name: Cut_Ribbon
// CODE: 189A
// WWWW: http://codeforces.com/contest/189/problem/A
// Author: Jan Krepl
// Tags: dp, brute force




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
// Top down dynamic programming 

// however bottow up would be much easier
// we can even iterate through all possible coefficients a, b ...:D


vector<int> memo(4001,-1); // memo[i] - maximum number of cuts fixed a,b,c with i remaining


int max_ribbon_pieces(int &n, int &a, int &b, int &c){
  if(memo[n] != -1){
    return memo[n];
  }
  // base case 1
  if(a > n & b > n & c > n){
    if(n > 0){
      return memo[n] = -500000000;
    }else{
      // n == 0
      return memo[n] = 0;
    }
  }

  // base case 1


  // inductive step
    // simply max (f(n - a,...), f(n - b,...), f(n - c,...)) .if possible
  int output = -500000000;
  if(n - a >= 0){
    int temp = n - a;
    output = max(output, 1 + max_ribbon_pieces(temp, a, b, c));

  }
  if(n - b >= 0){
    int temp = n - b;
    output = max(output, 1 + max_ribbon_pieces(temp, a, b, c));
  }
  if(n - c >= 0){
    int temp = n - c;
    output = max(output, 1 + max_ribbon_pieces(temp, a, b, c));
  }

  return memo[n] = output;

}

int main(){
  int N,a,b,c;
  cin >> N >> a >> b >> c;
  cout << max_ribbon_pieces(N,a,b,c) << endl;
}

