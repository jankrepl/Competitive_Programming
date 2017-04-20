// Name: Ciel_and_AB_Problem
// Problem_Code: CIELAB
// WWWW: https://www.codechef.com/problems/CIELAB
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility> 

using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    int true_diff = A - B;
    //find what the last digit is
    int last_digit = true_diff % 10;

    //change the last digit
    if(last_digit == 9){
        cout << true_diff - 1;
    }else{
        cout << true_diff + 1;
    }

}