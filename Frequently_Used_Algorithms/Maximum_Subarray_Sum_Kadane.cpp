// Algorithm: Maximum_Subarray_Sum_Kadane
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
// Find maximum contigous and noncontigous subbaray

// Algorithm logic for both n and c:
    // the solutions is equal to
    // max(max_subbaray_ending_at_0, max_subbaray_ending_at_1,..., max_subbaray_ending_at_(N-1))

    // the first element is simply input[0]...
    // the other elements are recursively:
        // CONTINGENT: 
            // max_subbaray_ending_at_i = max(max_subbaray_ending_at_(i - 1) + input[i], input[i])
        // NOT NECESSARILY CONTINGENT:
            // max_subbaray_ending_at_i = max( max_subbaray_ending_at_(i - 1) + input[i] , max(max_subbaray_ending_at_(i - 1), input[i]) )




/* Complexity */
// O(N)

/* Tips and tricks */



/* Example problem */



/* Implementation #1 */
long contiguous(vector<int> &numbers){
    int N = numbers.size();
    int max_so_far = numbers[0]; // biggest contingent subbaray sum so far
    int max_ending_here = numbers[0]; // 
    for(int i = 1; i < N; i++){
      max_ending_here = max(max_ending_here + numbers[i], numbers[i]);
      max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;

}

long noncontiguous(vector<int> &numbers){
    int N = numbers.size();
    int max_so_far = numbers[0]; // biggest noncontinguous subbaray sum so far
    int max_ending_here = numbers[0]; 
    for(int i = 1; i < N; i++){
      max_ending_here = max(max_ending_here + numbers[i], max(numbers[i],max_ending_here));
      max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;

}

