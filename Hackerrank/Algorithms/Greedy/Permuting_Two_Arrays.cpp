// Name: Permuting_Two_Arrays
// WWWW: https://www.hackerrank.com/challenges/two-arrays
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
// BE greedy! match smallest from one with the biggest from the other

int main() 
{
  int q;
  cin >> q;
  while(q--){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }        
    vector<int> B(n);
    for(int i = 0; i < n; i++){
      cin >> B[i];
    }

    // sort A
    sort(A.begin(), A.end());

    // reverse sort B        
    sort(B.rbegin(), B.rend());

    
    // sum and online check if all bigger than k
    vector<int> summa(n);
    for(int i = 0; i < n; i++){
      summa[i] = A[i] + B[i];
      if(summa[i] < k){
        cout << "NO" << endl;
        goto jump;
      } 
    }
    cout << "YES" << endl;
    jump:;
  }
}
