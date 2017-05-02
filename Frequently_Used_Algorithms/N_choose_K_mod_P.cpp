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

namespace imp_2{
  // n choose k mod p = fac_mod_p(n) * (inv(k) % p) * (inv(n - k) % p)
  // we use fermats little theorem to derive that for and integer a, its 
  // inverse module p is equal to a^(p-2) % p..
  // this requeires efficient exponentitat



  // Step 0 - Memoize factorials

  unsigned long upper_limit = 100;
  unsigned long p = 1000000007;
  vector<unsigned long> f_p(upper_limit,0);

  unsigned long factorial_mod(unsigned long n, unsigned long p){
    if( n == 0){
      return 1;
    }
    if( f_p[n] != 0){
      return f_p[n];
    }else{
      return f_p[n] = n * factorial_mod(n - 1, p);
    }

  }

  // Step 1 - Exponentiation by squaring
  // https://en.wikipedia.org/wiki/Exponentiation_by_squaring

  unsigned long pow_mod_p (unsigned long a, unsigned long b, unsigned long p){
    unsigned long x = 1, y = a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>p) x%=p;
        }
        y = (y*y);
        if(y>p) y%=p; 
        b /= 2;
    }
    return x;    

  }

  // Step 2 - Finding inverse 
  // Fermat little theorem
    unsigned long inverse(unsigned long n, unsigned long p)
  {
      return pow(n,p-2);
  }

  // Step 3 - Putting it all together
  unsigned long N_choose_K_mod_P(unsigned long n, unsigned long k, unsigned long p){
      return (f_p[n]*((inverse(f_p[k], p) * inverse(f_p[n-k], p)) % p)) % p;
  }





}
                

/* Implementation #3 */

