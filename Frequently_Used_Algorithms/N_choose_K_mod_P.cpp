// Algorithm: N_choose_K_mod_P
// Author: Jan Krepl

/* Libraries */
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

using namespace std;


/* Description */
// N choose K mod P, where P is a prime


/* Tips and tricks */



/* Example problem */



/* Implementation #1 - no mod */
// Straightforward stupid implementation

namespace imp_1{
    unsigned long factorial(int n){
  if(n == 0){
    return 1;
  }else{
    return long(n) * factorial(n - 1);
  }
}

unsigned long cut_fact(int n, int end){
  if(n == end){
    return end;
  }else{
    return long(n) * cut_fact(n - 1, end);
  }
}


unsigned long n_choose_k(int n, int k){
  if(k == 0 || n == k){
    return 1;
  }

  if(k == 1){
    return n;
  }

  if(n - k < k){
    return n_choose_k(n,n - k);
  }

  //main
  return cut_fact(n, n - k + 1)/factorial(k);
}

}


/* Implementation #2 */


/* Implementation #3 */

