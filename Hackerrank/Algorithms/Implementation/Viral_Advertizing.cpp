// Name: Viral_Advertising
// WWWW: https://www.hackerrank.com/challenges/strange-advertising
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int n;
    cin >> n;
    long shared_that_day = 5;
    long shared_overall = 5;
    long liked_that_day = 2;
    long liked_overall = 2;
    for(int i = 2; i <= n; i++){
        shared_that_day = 3*liked_that_day;
        shared_overall += shared_that_day;
        liked_that_day = floor(shared_that_day/2);
        liked_overall += liked_that_day;
    }
    cout << liked_overall;
    return 0;
}
