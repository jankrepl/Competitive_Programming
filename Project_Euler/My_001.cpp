#include <iostream>
using namespace std;

int main() {
    clock_t startTime = clock();
    long int sum = 0;
    for(unsigned int i = 1; i < 1000; ++i) {
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    cout << sum << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
}
