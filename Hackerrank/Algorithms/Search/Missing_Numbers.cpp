// Name: Missing_Numbers
// WWWW: https://www.hackerrank.com/challenges/missing-numbers
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m;
    vector<int> hist_A(10001,0),hist_B(10001,0);
    //READ
    cin >> n;
    vector<int> vec_A(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        vec_A[i] = temp;
        
    }
    
    cin >> m;
    vector<int>vec_B(m);
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        vec_B[i] = temp;
    }
    
    
    //populate histograms
    for(int i = 0; i < n; i++){
        hist_A[vec_A[i]] = hist_A[vec_A[i]] + 1;
    }
    
    for(int i = 0; i < m; i++){
        hist_B[vec_B[i]] = hist_B[vec_B[i]] + 1;
    }
    
    for(int i = 0; i < 10001; i++){
        if(hist_A[i] != hist_B[i]){
            cout << i << " ";
        }
    }
}
