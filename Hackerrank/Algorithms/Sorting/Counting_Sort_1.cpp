// Name: Counting_Sort_1
// WWWW: https://www.hackerrank.com/challenges/countingsort1
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {  
    vector<int> hist_a(100,0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        hist_a[temp]++;
    }
    
    for(int i = 0; i < 100; i++){
        cout << hist_a[i] << " ";
    }
    return 0;
}
