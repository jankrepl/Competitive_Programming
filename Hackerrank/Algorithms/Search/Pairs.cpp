// Name: Pairs
// WWWW: https://www.hackerrank.com/challenges/pairs
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
// Step 1) sort
// Step 2) Two pointer technique <- two pointers i,j at the beginning..
  //i <= j all the time...and only allowed to increase
    //if we overshoot the difference, i++
    // if we undershoot the difference , j++
    // if we make the difference, counter++ (and increment any pointer)


int pairs(vector < int > numbers ,int K) {
   int N = numbers.size();
   sort(numbers.begin(), numbers.end());
  // two pointer-index technique 
  int j = 0;
  int i = 0;

  int counter = 0;

  while(j < N){
        int difference = numbers[j] - numbers[i];
        if(difference > K){
          i++;
        }
        else if(difference < K){
          j++;
        }else{
          counter++;
          i++;
        }
    }
    return counter;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}
