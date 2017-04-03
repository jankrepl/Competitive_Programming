#include <iostream>
#include "Toolkit_functions.h"
using namespace std;



int main() {
    long sum = 0;
    //Determine all amicable numbers
    for(int i = 1; i <= 10000; i++){
        if(i < sum_all_divisors(i) && i == sum_all_divisors(sum_all_divisors(i))){
            sum += i + sum_all_divisors(i);
        }
    }

    cout << sum << endl;

    return 0;
}

