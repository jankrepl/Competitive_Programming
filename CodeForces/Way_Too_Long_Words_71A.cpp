// Name: Way_Too_Long_Words
// CODE: 71A
// WWWW: http://codeforces.com/problemset/problem/71/A
// Author: Jan Krepl
// Tags: Strings

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

string convert_me(string &s){
  int size = s.size();
  if(size <= 10){
    return s;
  }else{
    return s.substr(0,1) + to_string(size - 2) + s.substr(size - 1, 1);
  }
}


int main(){
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){
    string s;
    cin >> s;
    cout << convert_me(s) << endl;
  }
}

