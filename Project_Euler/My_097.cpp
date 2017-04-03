#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"



using namespace std;


//Problem 97
/*Simply use your biginteger class and the multiplication operand on it. Also, make sure after every
 * powering you only keep the last ten digits, otherwise it would get ugly.*/

int main() {
    biginteger a(number_to_vector_of_digits(2));
    biginteger power = a;
    for(long i = 1; i < 7830457; i++ ){
        power = power * a;
        power = power.last_digits(10);
        if(i % 100000 == 0){
            cout << i << endl;
        }
    }

    power = power.multiply(28433);

    biginteger one(number_to_vector_of_digits(1));
    power = power + one;

    power = power.last_digits(10);

    power.print();

}

