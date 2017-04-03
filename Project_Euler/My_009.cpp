#include<iostream>

using namespace std;

int main() {
    clock_t startTime = clock();
    long int product = 0;
    for(int a = 1; a <= 999; ++a){
        for(int b = 1; b <=999;b++ ){
            int c = (1000-a-b);
            if (a*a + b*b == c*c){
                product  = a*b*c;

            }
        }

    }
    cout << product <<  endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
}
