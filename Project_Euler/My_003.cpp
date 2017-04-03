// Find the largest prime factor of 600851475143

#include <iostream>
using namespace std;

#define COMP 6008514751432137

int main() {
    clock_t startTime = clock();
    unsigned long long int i = 2;
    unsigned long long int max = 0;
    while(i*i <= COMP) {

        if(COMP % i == 0) {

            bool check = true;

            for(unsigned int n = 2; n*n <= i; ++n) {

                if(i % n == 0) {
                    check = false;
                    break;
                }
            }

            if(check)
                max = i;

        }
        ++i;

    }

    if(COMP % max == 0)
        cout << max << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;

}