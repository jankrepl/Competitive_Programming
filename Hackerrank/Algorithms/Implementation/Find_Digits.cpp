// Name: Find_Digits
// WWWW: https://www.hackerrank.com/challenges/find-digits
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
        cin >> n;
        int x = n;
        int counter = 0;
        int digit;
        while(x > 0){
            digit = x % 10;
            if(digit != 0 && n % digit == 0){
                counter++;
            }
            x /= 10;
        }
        cout << counter <<endl;
    }
    return 0;
}
