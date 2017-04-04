// Name: Flipping_Bits
// WWWW: https://www.hackerrank.com/challenges/flipping-bits
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    //lets create 2^32 - 1 ...which is (1,1,....1) in binary representation - careful about overflow
    unsigned long god = ((1<<32));
    god -= 1;
    
    unsigned int finito = (unsigned int)god;
    while(T--){
        unsigned long  test;
        cin >> test;
        unsigned long result = (test^finito);
        cout << result << endl;          
    } 
    return 0;
}
