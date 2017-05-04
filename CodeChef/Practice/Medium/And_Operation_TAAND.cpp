// Name: And_Operation
// Problem_Code: TAAND
// WWW: https://www.codechef.com/problems/TAAND/
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
// Go from the left of bit representation of all numbers. If at least 2 of them are set, then delete those that are not set:D


typedef unsigned int uint;



int main(){
    int N;
    cin >> N;
    vector<bitset<32>> my_numbers(N,bitset<32>(0));
    vector<bool> is_candidate(N, true);

      for(int i = 0; i < N; i++){
        uint temp;
        cin >> temp;

        // initial 
        bitset<32> temp_bs(temp);
        my_numbers[i] = temp_bs;

    }
    int bit_position = 31;
    while(bit_position--){
      // count set bits
      int count_set = 0;
      for(int i = 0; i < N; i++){
        if(is_candidate[i] && my_numbers[i][bit_position]){
          count_set++;
        }
      }
      if(count_set >= 2){
        for(int i = 0; i < N; i++){
          if(is_candidate[i] && !my_numbers[i][bit_position]){
            is_candidate[i] = !is_candidate[i];
          }
        }
      }
    }

    int found = 0;
    long result = (long(1) << 32) - 1; // initialize 1111111111
    for(int i = 0; i < N; i++){
      if(is_candidate[i]){
        found++;
        result &= my_numbers[i].to_ulong();
        if(found == 2){
          break;
        }
      }
    }
    cout << result << endl;



}











