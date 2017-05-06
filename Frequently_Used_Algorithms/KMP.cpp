// Algorithm: KMP
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
// Knuth–Morris–Pratt
// An algorithm for finding a pattern string (size m) within a target string (size n)

// Finding a substring in a string is implemented by brute force in STL (str.find) -> complexity O(n * m)

// Algorithm:
    // Iterate from the first character in target and shift as long as pattern[i] == target [i]
    // As soon as they dont match look at the substring of the patter preceding the character that is different
        // if there exists a suffix and prefix of it that are equal, we simply start comparing as if we started before the suffix
        // if not, start iteration from the next element


/* Complexity */
// O(n + m)

/* Tips and tricks */



/* Example problem */



/* Implementation #1 */

// STEP 1) Precompute efficient suffix == prefix algo for a given pattern and save in a vector
void preprocessKMP(string pattern, vector<int> &f)
{
    // this is used for recognizing if prefix and suffix are the same 
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}

// STEP 2) Main Algorithm -> outputs the index where the pattern mathed the targest for the first time
            // if not found, outputs -1
int KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    vector<int>  f(m);     
    preprocessKMP(pattern, f);     
    int i = 0; // position in the target string
    int k = 0; // position in the pattern string
    int start_position = 0; // output winning index

    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
            start_position = i;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return start_position;
        }
        else
            k = f[k];
            start_position = i - k; // we just jump back to element which is just after the prefix for which suffix == prefix
    }
    return -1;
}

