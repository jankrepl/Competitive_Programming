
// Creates a sine function table
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include "Toolkit_functions.h"
#include <math.h>
#include <set>
#include <vector>

using namespace std;




int main() {
    int max_period = 0;
    int solution = 0;
    for(int i = 2; i <= 1000; i++ ){
        vector<int> result = long_division_one_in_numerator(i);
        int periood = result.size() - 1;
        if(max_period <= periood) {
            max_period = periood;
            solution = i;

        }
        print_vector<int>(result);

        cout <<"\n" << periood << endl;
    }
    cout<< "Max size before it starts to repeat size is: "<< max_period << "It is attained for d = " << solution ;
}



