#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"



using namespace std;

int main() {
    vector<int> input({0,1,2,3,4,5,6,7,8,9});
    vector<int> to_compare({2,3,5,7,11,13,17});
    long final_sum = 0;

    do{
        if(input[0]==0){
            continue;
        }
        bool include_me = true;
        for(int i = 1; i <= 7; i++){
            long number_to_test = vector_of_digits_to_number({input[i],input[i+1],input[i+2]});
            if(number_to_test % to_compare[i-1] != 0) {
                include_me = false;
                break;
            }
        }
        if(include_me){
            final_sum += vector_of_digits_to_number(input);
            print_vector<int>(input);
            cout << endl;
        }
    }while(next_permutation(input.begin(),input.end()));
    cout <<"Solution is: "<< final_sum;
}
