
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"


using namespace std;


bool is_increasing(long x){
    vector<int> digits = number_to_vector_of_digits(x);
    if(digits.size()==1){
        return false;
    }

    for(int i = 0; i < digits.size() - 1;i++){
        if(digits[i]>digits[i+1]){
            return false;
        }
    }
    return true;
}


bool is_decreasing(long x){
    vector<int> digits = number_to_vector_of_digits(x);
    if(digits.size()==1){
        return false;
    }
    for(int i = 0; i < digits.size() - 1;i++){
        if(digits[i]<digits[i+1]){
            return false;
        }
    }
    return true;

}

bool is_bubbly(long x){
    return !is_increasing(x) && !is_decreasing(x);
}

int main() {

    long i = 100; // No bubbly below 100
    long counter_bubbly = 0;

    while(100*counter_bubbly < 99*i){

        if(is_bubbly(i)){
            counter_bubbly++;
           // cout << i << endl;
        }
        ++i;


    }
    cout <<"Overall number:"<< i - 1 <<" Number of bubbly: " << counter_bubbly <<" proportion: " <<counter_bubbly/double(i);

}



