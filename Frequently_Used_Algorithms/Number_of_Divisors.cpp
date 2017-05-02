// Algorithm: Number_Of_Divisors
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
// We are given a long integer x and we would like to know how many divisors it has (including iteslt and 1)



/* Tips and tricks */



/* Example problem */



/* Implementation #1 */
// 2 step procedure - in code we optimize it and combine
    // 1) Prime Factorize x and only store exponents of distinct primes
    // 2) Use divisor function property that d(p_1^n * p_2^m) = (n+1)*(m+1) --  more one wiki


vector<int> prime_bank; // we assume we have a prime bank of sufficient size (prime_bank.back() >= x) ready...ith element is the ith smallest prime

long num_of_divisors(long x){
    long res = 1; // we will iteratively mupltiply, thats why initializing with 1

    int index = 0; // index of prime_bank element
    int exponent_count = 0; // counts the number of same primes...we initalize to one becaus

    do{
        int test_prime = prime_bank[index];

        if(x % test_prime == 0){
          x /= prime_bank[index];
          exponent_count++;
          continue;
        }else{
          if(exponent_count > 0){
            res *= exponent_count + 1;
          }
          if(x == 1){
              break;
          }
          index++;
          exponent_count = 0;

        }

    }while(true);

    return res;


}



