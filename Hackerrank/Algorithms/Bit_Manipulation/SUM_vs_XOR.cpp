// Name: SUM_vs_XOR
// WWWW: https://www.hackerrank.com/challenges/sum-vs-xor
// Author: Jan Krepl
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
// Strategy
// x + y == x ^ y <=> x & y == 0 ..
// so we simply just count the number of zeros in 
// binary representation of n and the result is
// two to the power of this count 

// for each zero..we can either have 0 and 1 ..while &
// always gives 0
// if there is a one..we only have 1 option..and that is 
// 1

long solution(long n){
  long result = 1;
  while(n > 0){
    if(n % 2 == 0){
      result *= 2;
    }
    n /= 2;
  }
  return result;
}
int main(){
    long n;
    cin >> n;
    cout << solution(n) << endl;
}
