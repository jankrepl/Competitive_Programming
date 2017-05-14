// Algorithm: Extended_Euclidian_Algorithm
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
// Used for finding the unique solution (x,y) (x,y \in Z) of Bezouts identity
// ax + by = gcd(a,b) ..where (a,b) given




/* Complexity */


/* Tips and tricks */



/* Example problem */



/* Implementation #1 */
// you can put x and y equal to anything when calling:D

int extendedGCD(int a, int b, int &x, int &y) {
    // everything divides 0
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1 = 0, y1 = 0, gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

/* Implementation #2 */


/* Implementation #3 */

