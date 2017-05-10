// Algorithm: Longest Increasing Subsequence
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
// Find the SIZE of the longest increasing subsequence in a given vector




/* Tips and tricks */



/* Example problem */



/* Implementation #1 */
// Complexity - O(N^2)
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
#include <typeinfo>
#include <cstring>
#include <queue>
#include <bitset>
using namespace std;


const int max_N = 1e6 + 1;

int memo[max_N]; // memo[i] = biggest increasing subsequence that ends with element seq[i] (including i)

int main(){
  int N;
  cin >> N;
  vector<int> seq(N);
  for(int i = 0; i < N; i++){
    cin >> seq[i];
  }

  // algorithm
    // recursive relation : memo[i] = max( memo[0] + 1, memo[1] + 1, ... , memo[i-j] + 1)
      //only for j where seq[j] > seq[i]...we are actually adding a higher element
  memo[0] = 1; // clear

  for(int i = 1; i < N; i++){
    int maxim = 1;
    for(int j = 0; j < i; j++){
      if(seq[i] > seq[j])
      maxim = max(maxim, memo[j] + 1);
    }
    memo[i] = maxim;
  }

  cout << *max_element(memo, memo + N) << endl;


}




/* Implementation #2 */


/* Implementation #3 */

