// Name: Save_the_Prisoner
// WWWW: https://www.hackerrank.com/challenges/save-the-prisoner
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long cases;
    cin >> cases;
    
    for(int i = 1; i <= cases; i++){
        long N,M,S;
        cin >> N >> M >> S;
        if((S+M - 1) % N == 0){
            cout << N << endl;
        }else{
            cout << (S+M - 1) % N << endl;
        }
    }
    return 0;
}
