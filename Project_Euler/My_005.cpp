// What is the smallest number evenly divisible by 1 up to 20.

#include<iostream>
using namespace std;

int main() {
    clock_t startTime = clock();
    int i = 1;

    bool check = true;

    while(1) {

        ++i;

        check = true;
        bool inner_break = false;

        for(unsigned int j = 1; j < 21; ++j) {

            if(i%j != 0){
                check = false;
                inner_break = true;
                break;
            }

        }

        if(!inner_break)
            break;

    }

    cout << i << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;

}