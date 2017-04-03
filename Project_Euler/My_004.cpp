// Find the largest palindromic number made from the product of two 3 digit numbers

#include<cstdlib>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

int main() {
    clock_t startTime = clock();
    unsigned int max = 0;

    for(unsigned int i = 999; i >= 99; --i)
        for(unsigned int j = 999; j >= 99; --j) {

            int prod = i*j;
            stringstream ss;
            ss << prod;
            string string = ss.str();
            int len = string.length();
            bool check = true;
            for(unsigned int k = 0; k < len/2.0; ++k)
                if(string[k] != string[(len-k)-1]) {

                    check = false;
                    break;

                }

            if(max <= prod && check)
                max = prod;

        }

    cout << max << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;

}