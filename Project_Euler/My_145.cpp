
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"

using namespace std;

bool has_odd_digits(vector<int> x){
    for (int i = 0; i < x.size(); i++){
        if(x[i] % 2 == 0){
            return false;
        }
    }
    return true;
}



int main() {
    int counter = 0;

    for(int i = 1; i <= 1000000000; i++){
        vector<int> original = number_to_vector_of_digits(i);
        vector<int> flipped = original;
        //zeros at the front back are not allowed
        if(original.front()==0 || original.back() == 0){
            continue;
        }
        //even + even = even
        if((original.front()%2 == 0) && (original.back()%2== 0) ){
            continue;
        }

        //odd + odd = even
        if((original.front()%2 != 0) && (original.back()%2 != 0) ){
            continue;
        }

        reverse(flipped.begin(), flipped.end());
        long test = 0;
        test =vector_of_digits_to_number(flipped) + vector_of_digits_to_number(original);

        vector<int> test_vector;
        test_vector = number_to_vector_of_digits(test);

        if(has_odd_digits(test_vector)){
            counter ++;
           cout << i << endl;

        }
    }
    cout << "\n" << counter ;
//    vector<int> flipped = {2,1};
//    cout << vector_of_digits_to_number(flipped);

}



