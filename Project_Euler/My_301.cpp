#include<iostream>
#include<vector>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"
#include <cmath>
#include <algorithm>


  


using namespace std;

//Problem 301



long nim_sum(long a,long b, long c){
    return a^b^c;
}

int main() {

    //the trick is that in each step of the game the nim sum is alternating between =0 and  >0...
    //since...in our game the player who has nim sum of zero is the loser...so once you start with nim sum zero you will end up with num sum zero

    long counter = 0;

    for (long i = 1; i <= pow(2,30); i++ ){
        if(nim_sum(i,2*i,3*i) == 0){
            counter++;
        }

        if(i % 100000000 == 0){
            cout << i << endl;
        }

    }

    cout <<"SOlution : " << counter;


}
