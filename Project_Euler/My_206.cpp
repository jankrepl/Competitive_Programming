#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"



using namespace std;
//problem 206

const int desired_size = 19;
const vector<int> non_blanks({1,2,3,4,5,6,7,8,9,0});

int main(){
    long print_counter = 0;
    biginteger one(number_to_vector_of_digits(10));
    biginteger test;
    test.a = {1,3,8,9,0,0,0,0,0,0};

    biginteger square = test*test;
    while(square.size() <= desired_size){
        vector<int> temp = square.export_odd_digits();
        if(non_blanks == temp){
            cout << "The solution is: ";
            test.print();
            cout<< "The square is: ";
            square.print();
            break;
        }
        if(print_counter % 2 ==0){
            cout << "Currently, we are at: ";
            test.print();
            cout << "These are the subindexes: ";
            print_vector<int>(temp);
            cout << endl;
            cout << "With a square: ";
            square.print();
            cout << endl;
        }
        print_counter++;

        test = test + one;
        square = test*test;
    }
//    for(int i = 1; i <= 1000; i++){
//        test = test + one;
//        test.print();
//    }
}


