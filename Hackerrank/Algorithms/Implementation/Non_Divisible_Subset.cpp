// Name: Non-Divisible Subset
// WWW: https://www.hackerrank.com/challenges/non-divisible-subset
// Author: Jan Krepl


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
#include <tuple>

using namespace std;


/* General strategy */
// We use the fact that (a + b) % k == 0 if and only if ((a % k) + (b % k) == 0 or (a % k) + (b % k) == k)
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Step 1) Create a histogram of remainders after dividing all elements by k
    vector<int> a_mod_k(k,0); // all remainders have values in 0,...,k-1
    for(int i = 0; i < n; i++){
        a_mod_k[a[i] % k]++;
    }

    //This histogram encodes all the important info, because the desired state is for each element is not to have 
    // a pairmate () -> a number that would cause it to sum of to 0 or k
    // 0 -> 0
    // 1 -> k-1
    // 2 -> k-2 ...
    // k-1 -> 1

    // So the final answer is n - number of pairmates we have to delete in order to make it perfect...
    // and the strategy is to delete the ones with lowest count


    int counter = 0;

    // remainder 0 has a special treatment ..it is
    if (a_mod_k[0] > 1){
        counter += a_mod_k[0] - 1;
    }

    // Also the middle element if k i even
    if (k % 2 == 0 && a_mod_k[k/2]  > 1){
        counter += a_mod_k[k/2] - 1;
    }

    // remaining elements
    for(int i = 1; i < k/2.0; i++){
        if(a_mod_k[i] > 0 || a_mod_k[k - i] > 0){
            counter += min(a_mod_k[i],a_mod_k[k - i]);
        }
    }

    cout << n - counter << endl;


}

