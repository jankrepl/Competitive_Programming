
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"

using namespace std;




int main() {
    // All will be stored as vector<int>
    // for loop..each number i will be first decomposed into digits vector and than this will be appanded to the overall vector

    vector<int> overall;
    vector<int> digits;
    long i = 0 ;
    while(overall.size()<= 1000000){
        digits = number_to_vector_of_digits(i);

        overall.insert(overall.end(),digits.begin(),digits.end());
        i ++;
    }
    vector<long> to_print = {overall[1],overall[10],overall[100],overall[1000],overall[10000],overall[100000],overall[1000000]};
    print_vector<long>(to_print);
    cout << "\nProduct:"<< overall[1]*overall[10]*overall[100]*overall[1000]*overall[10000]*overall[100000]*overall[1000000];
}



