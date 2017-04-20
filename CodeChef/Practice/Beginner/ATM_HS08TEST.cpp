// Name: ATM
// Problem_Code: HS08TEST
// WWWW: https://www.codechef.com/problems/HS08TEST
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
    int X;
    double Y;
    cin >> X >> Y;
    double fee = 0.5;
    if(X + fee <= Y && X % 5 == 0){
        printf("%.2f\n", double(Y - X - fee));
    }else{
        printf("%.2f\n", Y);
    }
}