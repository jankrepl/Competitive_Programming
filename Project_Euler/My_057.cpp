
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"
#include <math.h>
#include <set>
#include <vector>
#include "Toolkit_classes.h"
using namespace std;



//fraction dip_in( int level, int iteration_limit){
//    if (level == iteration_limit){
//        fraction temp(3,2);
//        return temp;
//
//    } else{
//        fraction a(1,1); // We can only sum and divide fractions
//
////        fraction temp1 = dip_in(level +1, iteration_limit);
////        fraction temp2 = a + temp1;
////        fraction temp3 = a/temp2;
////        fraction temp4 = a + temp3;
////
////        fraction temp = temp4;
//        fraction temp = a+a/(a + dip_in(level +1, iteration_limit));
//        temp.cancel_out();
//        return temp;
//    }
//
//
//
//
//
//}



int main() {



//    int counter = 0;
//    for(int i = 1; i <= 1000; i++){
//        fraction result = dip_in(1,i);
//
////        cout << result.numerator << "/" << result.denominator << endl;
//        int digits_num = number_to_vector_of_digits(result.numerator).size();
//        int digits_den = number_to_vector_of_digits(result.denominator).size();
//
////        cout << digits_num << " " << digits_den << endl;
//        if(digits_num > digits_den){
//            counter++;
//            cout << result.numerator << "/" << result.denominator << " Evaluated: " << result.evaluate() << endl;
//        }
//    }
//    cout << counter;


    // I defined a new class called biginteger...defined a sum operator on it..and used the fact that sequence of numerators and denominators can be written in terms of the previous elements
    biginteger num_now,den_now;
    biginteger num_prev(number_to_vector_of_digits(3));
    biginteger den_prev(number_to_vector_of_digits(2));

    int counter = 0;

    for(int i = 2; i <= 1000; i++){
        num_now = (num_prev + den_prev)+den_prev;
        den_now = (num_prev + den_prev);

        if(num_now.size()>den_now.size()){
            counter++;
            num_now.print();
            den_now.print();
            cout << endl;

        }

        num_prev = num_now;
        den_prev = den_now;
    }

    cout << counter;
}



