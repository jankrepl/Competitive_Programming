
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <math.h>
#include <set>
#include "Toolkit_classes.h"

using namespace std;

fraction::fraction(long numerator, long denominator) : numerator(numerator), denominator(denominator) {}


void fraction::cancel_out() {
    long gcd = __gcd(this->numerator,this->denominator);
    this->numerator =this->numerator/gcd;
    this->denominator = this->denominator/gcd;


}

fraction fraction::operator+(fraction rhs) {

    fraction temp(1,1);
    temp.numerator = this->numerator*rhs.denominator + rhs.numerator*this->denominator;
    temp.denominator = this->denominator*rhs.denominator;

    //cancel out
    temp.cancel_out();



    return temp;
}

fraction fraction::operator/(fraction rhs) {

    fraction temp(1,1);
    temp.numerator = this->numerator*rhs.denominator;
    temp.denominator = this->denominator*rhs.numerator;

    temp.cancel_out();


    return temp;
}

double fraction::evaluate() {
    return (1.0 + this->numerator)/(this->denominator);
}

void fraction::print_me() {
    cout << this->numerator << "/" << this->denominator << endl;

}


