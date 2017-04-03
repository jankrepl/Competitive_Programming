
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"
#include <math.h>
#include <set>
#include <vector>

using namespace std;


class fraction{
public:
    int numerator, denominator;

    fraction(int a, int b){
        numerator = a;
        denominator = b;
    }

    pair<fraction, bool> cancel(){
        //Output 0/1 if impossible to do the stupid cancel and bool false
        vector<int> numerator_digits = number_to_vector_of_digits(numerator);
        vector<int> denominator_digits = number_to_vector_of_digits(denominator);

        vector<int>::iterator first_position = find(numerator_digits.begin(),numerator_digits.end(),denominator_digits[0]);
        vector<int>::iterator second_position = find(numerator_digits.begin(),numerator_digits.end(),denominator_digits[1]);

        // GENERIC OUTPUT
        fraction temp(0,1); // output when nothing to cancel
        bool was_canceled = false;
        pair<fraction, bool> output(temp,was_canceled);


        //not found
        if(first_position - numerator_digits.begin() == 2 && second_position - numerator_digits.begin() == 2){
            return output;
        //
        }else if(first_position - numerator_digits.begin() == 1 ){
            fraction temp(*(first_position - 1),denominator_digits[1]);

            was_canceled = true;
            pair<fraction, bool> output(temp,was_canceled);
            return output;

        }else if(first_position - numerator_digits.begin() == 0 ){
            fraction temp(*(first_position + 1),denominator_digits[1]);

            was_canceled = true;
            pair<fraction, bool> output(temp,was_canceled);
            return output;

        }else if(second_position - numerator_digits.begin() == 1 ){
            fraction temp(*(first_position - 1),denominator_digits[0]);

            was_canceled = true;
            pair<fraction, bool> output(temp,was_canceled);
            return output;

        }else if(second_position - numerator_digits.begin() == 0){
            fraction temp(*(first_position + 1),denominator_digits[0]);

            was_canceled = true;
            pair<fraction, bool> output(temp,was_canceled);
            return output;

        }


    }

};


bool operator==(fraction LHS, fraction RHS){
    return LHS.numerator*RHS.denominator == LHS.denominator*RHS.numerator;

}


fraction vykratit(fraction LHS, fraction RHS){
    fraction temp(1,1);
    temp.numerator = LHS.numerator * RHS.numerator;
    temp.denominator = LHS.denominator * RHS.denominator;


    int gcd = __gcd(temp.numerator,temp.denominator);
    temp.numerator /= gcd;
    temp.denominator /= gcd;

    return temp;

}



int main() {

//    cout << equal;
    fraction output(1,1);

    for(int i = 11; i <= 99; i++){
        for(int j = 11; j < i; j++){
            fraction pokus(j,i);
            fraction result = pokus.cancel().first;
            if(pokus == result){
                cout << " Original fraction: " << pokus.numerator << "/"<< pokus.denominator << endl;
                cout << " Canceled fraction: " << result.numerator << "/"<< result.denominator << endl;
                cout << endl;
                output = vykratit(output,result);

            }
        }
    }

    cout << " Final product - fraction: " << output.numerator << "/"<< output.denominator << endl;


}




