// Name: Day_of_the_Programmer
// WWWW: https://www.hackerrank.com/challenges/day-of-the-programmer
// Author: Jan Krepl

#include <bits/stdc++.h>

using namespace std;


bool is_leap_julian(int y) {
    return (y%4 == 0);

}

bool is_leap_gregorian(int y){
    return (y%400 == 0) || (y%4 == 0 && y%100 != 0);

}

bool is_julian(int y){
    return y < 1918;

}

bool is_gregorian(int y){
    return y > 1918;

}



int main(){
    int y;
    cin >> y;

    if(is_gregorian(y)){
        if(is_leap_gregorian(y)){
            cout << "12.09." << y;
        }else{
            cout << "13.09." << y;
        }

    }else if(is_julian(y)){
        if(is_leap_julian(y)){
            cout << "12.09." << y;
        }else{
            cout << "13.09." << y;
        }


    }else{
        //switch year
        cout << "26.09." << y;
        
    }

    

}
