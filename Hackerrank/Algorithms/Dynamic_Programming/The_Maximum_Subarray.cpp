// Name: The_Maximum_Subarray
// WWWW: https://www.hackerrank.com/challenges/maxsubarray
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

int main(){
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++){
      cin >> numbers[i];
    }

    cout << contiguous(numbers) << " ";

    cout << noncontiguous(numbers) << endl;
  }



}




