
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"
#include <math.h>
#include <set>

using namespace std;

long next_in_chain(long x){;
    vector<int> digits = number_to_vector_of_digits(x);
    long temp = 0;
    for(vector<int>::iterator i = digits.begin(); i < digits.end(); i++){
        temp += factorial(*i);
    }
    return temp;
}

int chain_size(long x){
    int counter = 0;
    set<long> chain = {x};
    bool is_duplicate = false;

    while(!is_duplicate){
        pair<set<long>::iterator,bool>  ret;
        x = next_in_chain(x);
        ret = chain.insert(x);
        is_duplicate = !ret.second; // outputs true if inserted, false if already there
        counter++;
    }
    return counter;
}

int main() {
    int counter = 0;

    for (long i = 10; i < 1000000; i++) {


        if(chain_size(i) == 60){
            counter++;
        }

    }
    cout << counter;
}



