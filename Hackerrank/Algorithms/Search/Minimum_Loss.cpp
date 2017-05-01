// Name: Minimum_Loss
// WWWW: https://www.hackerrank.com/challenges/minimum-loss
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
#include <queue> 
using namespace std;




// Sort all prices (while keeping the old indices somewhere) with a clever comparator function
bool smaller(pair<int,long> &a, pair<int,long> &b){
  return a.second < b.second;
} 

int main(){
  int n;
  cin >> n;
  vector<pair<int,long>> indexed_prices(n);
  for(int i = 0; i < n; i++){
      indexed_prices[i].first = i;
      cin >> indexed_prices[i].second;
  }

  sort(indexed_prices.begin(),indexed_prices.end(),smaller);

  long minimum = numeric_limits<long>::max();;
  for(int i = 0; i < n - 1; i++){
    if(indexed_prices[i].first > indexed_prices[i+1].first){
      // the two prices are chronologically correct
      minimum = min(minimum, indexed_prices[i + 1].second - indexed_prices[i].second);
    }

  }

  cout << minimum << endl;


}



// 