// Name: Number_Of_Factors
// Problem_Code: NUMFACT
// WWWW: https://www.codechef.com/problems/NUMFACT
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
#include <tuple>
#include <typeinfo>
#include <cstring>
#include <queue>
using namespace std;


/* Strategy */
//1) Prime factorize all numbers and keep their counts aswell
//2) Use the divisor function beautiful property d(p_1^n * p_2^m) = (n+1)*(m+1)




vector<int> prime_factorize(vector<int> va, vector<int> &prime_bank){
    vector<int> output(1000001,0); //number line where ith element means the # occurances of i in prime representation
     for(auto a = va.begin(); a < va.end(); a++){ 
      int index = 0;
      bool same_prime = true;
      while(*a > 1){
          int test_prime = prime_bank[index];
          while(*a % test_prime != 0){
              index++;
              test_prime = prime_bank[index];
              same_prime = false;
          }
          *a /= prime_bank[index]; // divide a by its prime factor
          output[prime_bank[index]]++;
      }
    }
    return output;
}



bool is_prime(int a){
    if (a == 2) return true;
    for(int i = 3; i*i <= a; i += 2){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

vector<int> create_bank(int upper_limit){
    vector<int> prime_bank;
    for(int i = 2; i <= upper_limit; i++){
        if(is_prime(i)){
            prime_bank.push_back(i);
        }
    }
    return prime_bank;
}





int main(){
    int T;
    cin >> T;
    vector<int> prime_bank  = create_bank(1000000);
    while(T--){
        int N;
        cin >> N;
        vector<int> constituents(N);
        for(int i = 0; i < N; i++){
            cin >> constituents[i];
        }
        int maxim = *max_element(constituents.begin(), constituents.end());

        // Create prime vector factorization and sum for all numbers
        vector<int> result_bank = prime_factorize(constituents,prime_bank);
        // use divisor function property
        long res = 1;
        for(auto it = prime_bank.begin(); it < prime_bank.end(); it++){
            if(result_bank[*it] != 0){
                res *= (result_bank[*it] + 1);
            }
            if(*it > maxim){
              break;
            }
        }
        cout << res << endl;

    }
}
