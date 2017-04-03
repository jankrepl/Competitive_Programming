//
// Created by Jan Krepl on 08.01.17.
//

#ifndef PROJECT_EULER_TOOLKIT_TOOLKIT_CLASSES_H
#define PROJECT_EULER_TOOLKIT_TOOLKIT_CLASSES_H

#include <iostream>
#include <vector>

using namespace std;


class fraction{
public:
    long numerator,denominator;

    fraction(long numerator, long denominator);

    fraction operator+(fraction rhs);

    fraction operator/(fraction rhs);

    void cancel_out();

    double evaluate();

    void print_me();


};

class biginteger{
public:
    //represents digits
    vector<int>  a;


public:

    //best way to initiate is biginteger a(number_to_vector_of_digits(1312));
    biginteger(const vector<int> &a);

    biginteger();

    biginteger concatenate(biginteger rhs);

    biginteger operator+(biginteger rhs);

    biginteger operator^(int rhs);

    biginteger operator*(biginteger rhs);

    bool operator>(biginteger rhs);

    bool operator<(biginteger rhs);

    bool operator==(biginteger rhs);

    bool is_pandi_9();

    bool is_pandi_any();

    bool is_palindrome();
    biginteger multiply(int m);

    int sum_digits();

    biginteger reverse_me();

    biginteger last_digits(int digits);

    vector<int> export_odd_digits();

    void print();

    int size();

};
#endif //PROJECT_EULER_TOOLKIT_TOOLKIT_CLASSES_H
