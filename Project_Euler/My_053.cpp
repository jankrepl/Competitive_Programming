#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

//Problem 53




using namespace std;

int main() {
    long counter = 0;

    for(int i = 1; i <= 100; i++){
        for(int j = 1 ; j <= i; j++){
            if(combination_number(i,j) >= 1000000){
                //need to deal with overflow
                    counter += i + 1 - (2 * (j));
//                    cout << i << " " << j << " " << combination_number(i,j) << endl;
                break;
            }
        }
    }
   cout << "final answer: "<< counter;

}
