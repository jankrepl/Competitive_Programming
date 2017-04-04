// Name: Sherlock_and_Squares
// WWWW: https://www.hackerrank.com/challenges/sherlock-and-squares
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_square(long long n){
    float sr = sqrt(n);
    return (sr == floor(sr)); 
}

int main() {
    int T;
    cin >> T;
    
    for(int i = 1; i <= T; i++) {
        long long A, B;
        cin >> A >> B;

        long l = long(floor(sqrt(A)));

        long counter = 0;
        while (l * l <= B) {
            if (l * l >= A) {
                counter++;
            }
            l++;

        }
        cout << counter << endl;
    }
    return 0;
}
