#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Toolkit_functions.h"
using namespace std;


#define loop(i,n) for(int i = 2; i <= n; i ++)

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double max = 0.0;
    int winner = 0;

    loop(i,1000000){
        if(double(i)/totient(i)>max){
            max = double(i)/totient(i);
            winner = i;

            cout << winner << " " << max << endl;
        }
    }
    cout << winner;
}