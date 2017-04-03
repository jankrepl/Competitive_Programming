// Name: Time_Conversion
// WWWW: https://www.hackerrank.com/challenges/time-conversion
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string time;
    cin >> time;
    string string_hh = time.substr(0,2);
    string string_mm = time.substr(3,2);
    string string_ss = time.substr(6,2);

    int hh = stoi(string_hh);
    if(time[8] == 'A' && string_hh != "12"){
       //no changes
    }
    else if(time[8] == 'A' && string_hh == "12"){
        string_hh = "00";

    }else if(time[8] == 'P' && string_hh != "12"){
        hh += 12;
        string_hh = to_string(hh);

    }else{
    }

    cout << string_hh << ":" << string_mm << ":" << string_ss << endl;
}


