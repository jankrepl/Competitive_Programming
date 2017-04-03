// Name: Pangrams
// WWWW: https://www.hackerrank.com/challenges/pangrams
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    getline(cin,input);
    vector<int> counter(26,0);
    for(int i = 0; i < input.size(); i++){
        if(isupper(input[i])){
            input[i] = tolower(input[i]);
        }
        if((int)input[i] - 97 >= 0 && (int)input[i] - 97 < 26 && counter[(int)input[i] - 97] == 0){
            counter[(int)input[i] - 97] = 1;
        }
    }
    int result = accumulate(counter.begin(),counter.end(),0);
    if(result == 26){
        cout << "pangram";
    }else{
        cout << "not pangram";
    }
    return 0;
}


