#include<iostream>

using namespace std;

bool isprime(int x){
    for (int j=2; j<int(x/2);++j){
        if(x%j == 0){
            return false;
        }
    }
    return true;

}

int main() {
    clock_t startTime = clock();
    long int sum = 2; //Two is already included

    for(int i = 3; i<2000000;i+=2){
        if (isprime(i)){
            sum += i;
        }
    }
    cout << sum << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
}

