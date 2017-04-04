// Name: Chocolate_Feast
// WWWW: https://www.hackerrank.com/challenges/chocolate-feast
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;

        int chocolates_current = n/c;
        int chocolates_overall = chocolates_current;
        int  spare_wrappers = chocolates_current;
        int wrappers_overflow = spare_wrappers%m;

        while(spare_wrappers >= m){
            chocolates_current = spare_wrappers/m;
            chocolates_overall += chocolates_current;
            spare_wrappers = chocolates_current + wrappers_overflow;
            wrappers_overflow = spare_wrappers % m;
        }

        cout << chocolates_overall << endl;
    }
    return 0;
}


