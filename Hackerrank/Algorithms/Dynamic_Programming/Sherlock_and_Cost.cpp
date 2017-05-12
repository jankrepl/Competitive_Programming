// Name: Sherlock_and_Cost
// WWWW: https://www.hackerrank.com/challenges/sherlock-and-cost
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
using namespace std;


/* Strategy */
// Claim: The optimal solution will only consists of 1 or B_i
  // Proof: By contradiction. Assume not true, then at one point k we picked
  // 1 < Ak < Bk ...However, we could increase the sum..because |A_k - A_(k - 1)| 
    // if A_k >= A_k-1 ..then chosing A_k = B_k will make the |A_k - A_(k - 1)| bigger
    // if A_k < A_k-1 ...then choosing A_k = 1 will make the |A_k - A_(k - 1)|  bigger


// Bottom up dynamic programming
// We will create 3 memo tables
  // H
    // H[i] is the solution in the first i where we take A[i] == B[i]
      // H[i] = max(L[i - 1] + B[i] - 1, H[i - 1] + |B[i] - B[i - 1]| )
  // L
    // L[i] is the solution in the first i where we take A[i] == 1
      // L[i] = max( L[i - 1] + 1 - 1,  H[i - 1] + B[i - 1] - 1)
  // F
    // F[i] is the final table

int main(){
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<int> B(N);
    for(int i = 0; i < N; i++) cin >> B[i];

    // initialize memo tables -- note that there are only N - 1 summands..however we model it in a way there is an initial
      // summand of 0
    vector<int> H(N,0), L(N,0), F(N,0);


    for(int i = 1; i < N ; i++){
      // update L
      L[i] = max(L[i - 1], H[i - 1] + B[i - 1] - 1);


      // update H
      H[i] = max(L[i - 1] + B[i] - 1, H[i - 1] + abs(B[i] - B[i - 1]));


      // Update F
      F[i] = max(H[i],L[i]);

    }

    cout << F[N - 1] << endl;

  }
}






