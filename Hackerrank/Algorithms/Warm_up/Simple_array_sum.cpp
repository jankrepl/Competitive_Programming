// Name: Simple_Array_Sum
// WWWW: https://www.hackerrank.com/challenges/simple-array-sum
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
    vector<int> arr(n);
    long result = 0;
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
        result += arr[arr_i];
    }
    cout << result;
    return 0;
}