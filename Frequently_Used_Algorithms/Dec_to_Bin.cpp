// Algorithm: Dec_to_Bin
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
// Inputs an unsigned long (64 bits) and outputs its binary representation



/* Tips and tricks */


/* Example problem */


/* Implementation #1 */
#include <bitset>

string dec_to_bin_1(ulong x){
    // bitset is a separate class 
    bitset<64> my_bitset(x);
    return my_bitset.to_string();
}
// can easily convert to vector of digits from the string if necessary


/* Implementation #2 */
vector<int> dec_to_bin_2(ulong x){
    // 
    vector<int> output(64);
    int i = 64;
    while(i--){
        output[i] = x % 2;
        x /= 2;
    }
    return output;
}


