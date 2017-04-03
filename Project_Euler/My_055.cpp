#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

//Problem 55




using namespace std;

int main() {
    int counter = 0;
    for(int i = 1; i < 10000; i++) {
        biginteger sum(number_to_vector_of_digits(i));
        bool is_lychrel = true;
        int iterations = 1;
        while (iterations < 50) {
            biginteger reverse = sum.reverse_me();
            sum = sum + reverse;

            if(sum.is_palindrome()){
                is_lychrel = false;
                break;
            }
            iterations++;
        }
        if(is_lychrel){
            counter++;
        }
    }

    cout << "SOLUTION: " << counter;


}

