
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"

using namespace std;


bool is_triangular(long x){
    double a = 1.0/2;
    double b = 1.0/2;
    double c = -x;

    double discriminant = b*b - 4*a*c;

    double solution = (-b + sqrt(discriminant))/(2*a);
    double rhs = floor(solution) + 0.0;
    return solution == rhs;

}

bool is_pentagonal(long x){
    double a = 3.0/2;
    double b = -1.0/2;
    double c = -x;

    double discriminant = b*b - 4*a*c;

    double solution = (-b + sqrt(discriminant))/(2*a);
    double rhs = floor(solution) + 0.0;
    return solution == rhs;

}

bool is_hexagonal(long x){
    double a = 2.0;
    double b = -1.0;
    double c = -x;

    double discriminant = b*b - 4*a*c;

    double solution = (-b + sqrt(discriminant))/(2*a);
    double rhs = floor(solution) + 0.0;
    return solution == rhs;

}

int main() {
    int counter = 0;
    long iterator = 1;
    while(counter != 3){
        if(is_triangular(iterator) && is_pentagonal(iterator) && is_hexagonal(iterator)){
            cout << iterator << endl;
            counter ++;
        }
        iterator++;
    }
}


