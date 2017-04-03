// Name: Staircase
// WWWW: https://www.hackerrank.com/challenges/staircase
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
    string space(n-1, ' ');
    string hash(1, '#');

    for(int i = 1; i <= n; i++){
        cout << space << hash << endl;
        space.pop_back();
        hash.push_back('#');
    }
}
