#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

using namespace std;


int main() {



    biginteger winner(number_to_vector_of_digits(123456789));

    for(int i = 1; i < 99999; i++ ){

        biginteger tester(number_to_vector_of_digits(i));
        bool under_9_digits = true;
        int multiplier = 2;

        while(under_9_digits){
            //tester is nine digit
            if(tester.size() == 9 && tester.is_pandi_9() && tester > winner){
                cout << "I am an intermediary winner: ";
                winner = tester;
                break;
            }else{
                tester.print();
                biginteger product;
                product = tester.multiply(multiplier);
                tester = tester.concatenate(product);
                multiplier++;
                under_9_digits = tester.size() <= 9;
            }
        }
    }
    cout << "I am THEEE winner: ";
    winner.print();
//    biginteger m(number_to_vector_of_digits(123456789));
//    biginteger n(number_to_vector_of_digits(1));
//    biginteger result;
//
//    result =  n.multiply(1);
//    result.print();
//    result =  n.multiply(2);
//    result.print();
//    result =  n.concatenate(n.multiply(3));
//    result.print();

//    bool test = n > m.;
//    bool test2 = n < m;
//    bool test3 = n == m;
//    bool test4 = m.is_pandi_9();
//    result.print();
//    cout << test << " "<< test2 <<" "<< test3<<" "<< test4;
//    return 0;
}
3r