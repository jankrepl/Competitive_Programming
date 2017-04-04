// Name: Service_Lane
// WWWW: https://www.hackerrank.com/challenges/service-lane
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int minimum(int a,int b){
    return min(a,b);
    
}

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0; width_i < n; width_i++){
       cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int i;
        int j;
        cin >> i >> j;
        cout << accumulate(width.begin() + i, width.begin() + j + 1, 100, minimum) << endl;
    }
    return 0;
}
