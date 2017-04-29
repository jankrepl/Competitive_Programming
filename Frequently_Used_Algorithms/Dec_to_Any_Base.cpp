// Algorithm: Dec_to_Any_Base
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

typedef vector<int> vi;


/* Description */
// Convertest unsigned long in decimal to a representation in a selected base



/* Tips and tricks */


/* Example problem */


/* Implementation #1 */

vi dec_to_any_base(ulong a, int base){
    vi output;
    while(a > 0){
        output.push_back(a % base);
        a /= base;
    }
    reverse(output.begin(), output.end());
    return output;
}
