// Name: Diagonal_Difference
// WWWW: https://www.hackerrank.com/challenges/diagonal-difference
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    long ld = 0;
    long rd = 0;
    vector<vector<int> > a(n, vector<int>(n));
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          cin >> a[a_i][a_j];
           if(a_i == a_j){
               ld += a[a_i][a_j];
           }
           if(a_i == n - a_j - 1){
               rd += a[a_i][a_j];
           }
       }
    }
    cout << abs(ld - rd);
    return 0;
}
