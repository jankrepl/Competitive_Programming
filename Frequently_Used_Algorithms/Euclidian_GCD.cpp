// Algorithm: Euclidian_GCD
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

typedef unsigned long ulong;


/* Description */
// Greatest common divisor algorithm


/* Tips and tricks */


/* Example problem */


/* Implementation #1 - subtraction */
// recursion too deep 

ulong  gcd_1(ulong a, ulong b){
    if(a == b || a == 0 || b == 0){
        return max(a,b);
    }

    if(a < b){
        return gcd_1(b,a);
    }

    return gcd_1(a - b, b);
}



/* Implementation #2 - modulo */

ulong  gcd_2(ulong a, ulong b){
    if(a % b == 0){
        return b;
    }

    if(a < b){
        return gcd_2(b,a);
    }

    return gcd_2(a % b, b);
}

