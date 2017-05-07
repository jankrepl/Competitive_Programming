// Name: Jim_and_the_Orders
// WWWW: https://www.hackerrank.com/challenges/jim-and-the-orders
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
// Straightforward... just need to implement(overload) < operator on pair<int,int>

bool smaller(pair<int,int> &a, pair<int,int> &b){
  return (a.second < b.second || (a.second == b.second && a.first < b.first));
}

int main() 
{
  int N;
  cin >> N;
  vector<int> t(N);
  vector<int> d(N);

  for(int i = 0; i < N; i++){
    cin >> t[i] >> d[i];
  }

  vector<pair<int,int>> result(N);
  for(int i = 0; i < N; i++){
    result[i].first = i ;
    result[i].second = t[i] + d[i];
  }
  sort(result.begin(), result.end(), smaller);

  for(int i = 0; i < N; i++){
    cout << result[i].first + 1<< " ";
  }
  cout << endl;
}
