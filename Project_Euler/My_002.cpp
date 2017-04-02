#include<iostream>

using namespace std;

int main() {
    clock_t startTime = clock();
    int i = 1;
    int j = 1;
    int k;
    int sum = 0;

    while(j <= 400000000) {

        if(j % 2 == 0)
            sum += j;

        k=j;
        j += i;
        i=k;

    }

    cout << sum << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;

}