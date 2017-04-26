// Algorithm: Sieve_of_Eratosthenes
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
// Generates all prime numbers smaller or equal to a certain bound
//
// We start from 0 and go over numbers in sieve that == true. For each number we find all its multiples lower than the bound.
// These numbers are then saved saved in sieve as == false

/* Tips and tricks */


/* Example problem */


/* Implementation #1 */

// redefine long names
typedef unsigned int uint;


uint sieve_upper_limit = 1000000000; // we defined it globally
vector<bool> sieve(sieve_upper_limit,true); // we first assume that all numbers are prime numbers


void populate_sieve(uint upper_limit){
    sieve[0] = false; // 0 not prime
    sieve[1] = false; // 1 not prime

    for(uint i = 2; i <= upper_limit; i++){
        if(sieve[i]){
            uint multiplier = 2;
            while(multiplier * i <= upper_limit){
                sieve[multiplier * i] = false;
                multiplier++;
            }
        }
    }
}



