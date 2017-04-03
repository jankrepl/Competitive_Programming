#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

//Problem 56




using namespace std;

int main() {
    int winner = 0;
    for (int a = 1; a < 100; a++){
        biginteger temp(number_to_vector_of_digits(a));
        biginteger copy = temp;
        for(int b = 2; b <= 100; b++){
            temp = temp*copy;
            if(temp.sum_digits()>winner){
                winner = temp.sum_digits();
                cout << a << "^" << b << " has a sum of digits equal to: " << winner << endl;
                biginteger a_bi(number_to_vector_of_digits(a));
                biginteger c = a_bi^b;
                c.print();


            }
        }
    }

    cout << "The biggest sum is : " << winner;

}
