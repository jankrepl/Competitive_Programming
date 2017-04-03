#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

//Problem 63




using namespace std;

int main() {
    int counter = 0;
        for(int a = 1; a <= 100; a++){
            for(int b = 1; b <= 100; b++){
                biginteger a_bi(number_to_vector_of_digits(a));
                biginteger product = a_bi ^ b;
                if(product.size() == b){
                    counter++;
                }

            }
        }
    cout << counter;

}
