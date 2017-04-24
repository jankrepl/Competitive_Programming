// Name: Mixtures_v2
// Problem_Code: MIXTURES
// WWW: https://www.codechef.com/problems/MIXTURES
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

using namespace std;

                        /* Strategy */
// TOP DOWN RECURSION
// Notice that the solution is only a function of the array -> f(potions)
// Let as define the smoke and value arrays
// Let s[i][j] := f(potions[i:j])    -- MATLAB NOTATION... minimum smoke after mixing the range into 1
// Let c[i][j] := color_of_the resulting mixture 
// 
// APPROACH: s[i][j] = min_over_all_m_in_{i,...j - 1} (s[i][m] + s[m + 1][j] + (c[i][m]*c[m+1][j]))
// left_subbarray + right_subarray + smoke_after_mixing them
// OBSERVATION: s[i][i+1] = potions[i]*potions[i+1] // BASE CASE
// s[i][j] = 
// Improvements -> f is symmetric..meaning that f(potions) = f(reverse(potions))


// Set up memo tables -  dont forget to define and then clear after each test case 
    // its easier to work with c-style array for this purpose
long s[101][101]; // 101 is the max number of potions



// Prelims
long inf = numeric_limits<long>::max();


// Functions


long f(vector<int> &potions_partial_sum, int i, int j){
    assert(i <= j);

    if(s[i][j] != 0) return s[i][j];

    if(i == j) return 0;


    // Define a function that will help us determine colours of subbarays
    #define sub_c(l,r) (((potions_partial_sum[r] - (l > 0 ? potions_partial_sum[l - 1] : 0)) % 100 + 100) % 100)

    long minimum_temp = inf;
    for(int m = i; m < j; m++){
        int color_left_subarray = sub_c(i,m);
        int color_right_subarray = sub_c(m+1,j);
        long result_sub = f(potions_partial_sum,i,m) + f(potions_partial_sum,m+1,j) + color_left_subarray*color_right_subarray;
        minimum_temp = min(minimum_temp, result_sub);
    }
    // memoize
    s[i][j] = minimum_temp;

    // return
    return s[i][j];
}

void print_me(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


int main(){

    while(cin){
        int N;
        cin >> N;
        vector<int> potions(N);
        for(int i = 0; i < N; i++){
            cin >> potions[i];
        }


        // clear memo table
        memset(s, 0, sizeof(s));

        // Populate color table - its independent of how you mix it... because (a + b) & 100 = ((a % 100) + (b % 100)) % 100
        // // too slow too stiff:D -- why to compute them all.. not necessary
        // for(int i = 0; i < N; i++){
        //     for(int j = i; j < N; j++){
        //         c[i][j] = accumulate(potions.begin() + i, potions.begin() + j + 1, 0, [](int x, int y){return (x + y)% 100;}) % 100;
        //     }
        // }
        vector<int> potions_partial_sum(N);
        partial_sum(potions.begin(), potions.end(), potions_partial_sum.begin());

        

        cout << f(potions_partial_sum, 0, N - 1) << endl;

    }
}



