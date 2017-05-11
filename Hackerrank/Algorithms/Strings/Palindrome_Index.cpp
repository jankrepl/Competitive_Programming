// Name: Palindrome_Index
// WWWW: https://www.hackerrank.com/challenges/palindrome-index
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
// Standard is_palindrome checker but give the string 1 additional chance:)...if it fails on one character,
// just remove it and recursively check if the substring is a palindrome


// if palindrome...return -2
// if not palindrome..return -1

int is_palindrome(string s, int penalty){
  int n = int(s.size());
  for(int i = 0; i < n; i++){
    if(s[i] != s[n - i - 1]){
      if(penalty == 0){
        string temp1 = s, temp2 = s;
        temp1.erase(i,1);
        temp2.erase(n - i -1, 1);

        if(is_palindrome(temp1,1) != -2 && is_palindrome(temp2,1) != -2){
          return -1;
        }else if(is_palindrome(temp1,1) == -2){
          return i;
        }else{
          return n - i - 1;
        }
      }else{
        return -1;
      }
    }
  }
  return -2;
}


int main(){
  int T;
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    int ans = is_palindrome(s,0) ;
    cout << (ans < 0 ? -1 : ans) << endl;
  }
}

