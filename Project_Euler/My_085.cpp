
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"

using namespace std;



int counting(int a, int b){

    int counter = 0;

    for(int i = 1; i <= a; i++){
        for(int j = 1; j<= b; j++){
            counter += (a-i + 1)* (b-j +1);
        }
    }
    return  counter;
}


int main() {
    int a = 100;
    int b = 100;

    int smallest_error = 2000000;
    int solution = 0;


    int counter = 0;

    for(int i = 1; i <= a; i++){
        for(int j = 1; j<= b; j++){
            if(abs(counting(i,j) - 2000000) < smallest_error){
                solution = i*j;
                smallest_error = abs(counting(i,j) - 2000000);
            };

        }
    }

    cout << solution << " error commited " << smallest_error;
}



