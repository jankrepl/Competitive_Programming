// Name: Root_of_the_Problem 
// Problem_Code: TREEROOT
// WWWW: https://www.codechef.com/problems/TREEROOT
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


/* Strategy */
// Lets define two numbers: 
  // s_id = sum of all provided ids
  // s_sid = sum of all provided id sums
// We claim that the id of the root = s_id - s_sid
// Explanation: the parent id is not in any of the sums..however all
// all the sums contain all remaining ids

int main(){
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    long ans = 0;
    while(N--){
      int id, sum;
      cin >> id >> sum;
      ans += id - sum;
    }
    cout << ans << endl;
  }

}


  