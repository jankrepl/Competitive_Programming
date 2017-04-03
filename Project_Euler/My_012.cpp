// Calculate the value of the first triangular number to have over 500 divisors.

#include<iostream>
#include <cmath>
using namespace std;

int main() {

    unsigned long long int i = 1;
    unsigned long long int sum = 0;

    while(1) {

        sum += i;
        int numD = 2;

        for(unsigned long long int n = 2; n < sqrt(sum); ++n)
            if(sum % n == 0)
                numD+=2;

        if(numD > 500) {
            cout << sum << endl;
            return 0;
        }

        ++i;

    }

    return 0;

}