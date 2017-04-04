// Name: Counter_Game
// WWWW: https://www.hackerrank.com/challenges/counter-game
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



bool is_power_of_two(unsigned long long x){
    //There is exactly one 1 in the binary representation of x
    for(int i = 0 ; i < 64; i++ ){
        unsigned long long temp = (unsigned long long)((unsigned long long)1 << i);
        if(x == temp){
            return true;
        }
    }
    return false;
}

unsigned long long largest_power_of_two_less_than(unsigned long long x){
    unsigned long long i = 0;
    while(x > ((unsigned long long)1 << i) && i < 64){
        i++;
    }
    return (unsigned long long)(((unsigned long long)1 << (i - 1)));
}


int main() {

    int T;
    cin >> T;
    long long counter = 0;
    while(T--){
        unsigned long long N;
        cin >> N;
        bool louise_winner = false;
        while(N != 1){
            louise_winner = !louise_winner;
            if(!is_power_of_two(N)){
                N -= largest_power_of_two_less_than(N);
            }else{
                N /= 2;
            }
            counter++;

            if(counter % 1000000 == 0){
                cout << counter << "  "<< N << endl;


            }

        }
        if(louise_winner){
            cout << "Louise" << endl;
        }else{
            cout << "Richard" << endl;
        }

    }

}

