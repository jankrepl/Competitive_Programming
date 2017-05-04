// Name: Watermelon
// CODE: 4A
// WWWW: http://codeforces.com/problemset/problem/4/A
// Author: Jan Krepl
// Tags: Brute Force, Math

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
#include <queue>
using namespace std;


int main(){
  /* Strategy */
  // Even plus even is even..therefore we have to have an even input
  // 2 is too small..every other higher even number works fine
  int N;
  cin >> N;
  cout << (N > 2 && N % 2 == 0 ? "YES" : "NO") << endl;
}