// Name: Sherlock_and_The_Beast 
// WWWW: https://www.hackerrank.com/challenges/sherlock-and-the-beast
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


/* Brute force */


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
      
      for(int i = 0; i <= n; i++){
        if((n - i) % 3 == 0 && (i % 5) == 0){
          for(int j = 0; j < n - i; j++){
            cout << 5;
          }
          for(int j = 0; j < i; j++){
            cout << 3;
          }
          cout << endl;
          goto jump;
        }
      }
      cout << -1 << endl;


      jump:;


    }


    return 0;
}



