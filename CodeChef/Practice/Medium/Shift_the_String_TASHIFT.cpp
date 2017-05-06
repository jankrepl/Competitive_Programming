// Name: Shift_the_String
// Problem_Code: TASHIFT
// WWW: https://www.codechef.com/problems/TASHIFT
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
// We will do a binary search of the maximal substring size...
// And for a given substring size we use the KMP algorithm to find the index of matched pattern

// void 
void preprocessKMP(string pattern, vector<int> &f)
{
    // this is used for recognizing if prefix and suffix are the same 
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
//check whether reference string contains pattern 
int KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    vector<int>  f(m);     
    preprocessKMP(pattern, f);     
    int i = 0; // position in the target string
    int k = 0; // position in the pattern string
    int start_position = 0; // output winning index

    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
            start_position = i;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return start_position;
        }
        else
            k = f[k];
            start_position = i - k;
    }
    return -1;
}




int find_me(string &target, string &pattern){
  return KMP(pattern,target);
}


int my_binary_search(string &A, int N, string &bank){
  // Prelims


  // Algorithm
  vector<int> sizes_to_test(N);
  iota(sizes_to_test.begin(), sizes_to_test.end(),1); // {1,2,3...,N}
  int substring_size; // initial value in the middle
  int winner;

  while(!sizes_to_test.empty()){
    substring_size = sizes_to_test[sizes_to_test.size()/2];
    string temp = A.substr(0,substring_size); // first substring_size characters of A
    int found_position = find_me(bank, temp);
    if(found_position != -1){
      // was found...we can try to find a bigger substring
      winner = int(found_position);
      vector<int> temp_v(sizes_to_test.begin() + sizes_to_test.size()/2 + 1, sizes_to_test.end());
      sizes_to_test = temp_v;

    }else{
      // was not found..we need to find a smaller substring
      vector<int> temp_v(sizes_to_test.begin(), sizes_to_test.begin() + sizes_to_test.size()/2);
      sizes_to_test = temp_v; 
    }

  }

  return winner;
}


int main(){
  // A = ccadd
  // B = bddcc / bddc <- by adding n-1 characters we can easily create all possible shifts

  int N;
  cin >> N;

  string A,B;
  cin >> A >> B;

  B += B.substr(0, N - 1);

  // 
  int result = my_binary_search(A,N,B);
  cout << result << endl;

}










