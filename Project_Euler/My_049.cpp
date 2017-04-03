#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

//Problem 49

using namespace std;

int main() {

    //Generate all primes from 1000 to 9999;

    vector<int> my_primes;

    for(int i = 1000; i < 10000; i++){
        if(is_prime(i)){
            my_primes.push_back(i);
        }
    }

    cout << "There are " << my_primes.size() << " primes" << endl;

    for(vector<int>::iterator it = my_primes.begin(); it < my_primes.end(); it++){
        for(vector<int>::iterator jt = it + 1; jt < my_primes.end(); jt++){
            for(vector<int>::iterator kt = jt + 1; kt < my_primes.end(); kt++){

                if((*jt - *it) == (*kt - *jt)){
                    if(is_permutation(number_to_vector_of_digits(*it),number_to_vector_of_digits(*jt)) &&
                                                    is_permutation(number_to_vector_of_digits(*jt),number_to_vector_of_digits(*kt))){
                        cout << *it << " " << *jt << " " << *kt << endl;
                        break;
                    }
                }
            }
        }
    }

}
