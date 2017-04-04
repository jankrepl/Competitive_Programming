// Name: Modified_Keprekar_Numbers
// WWWW: https://www.hackerrank.com/challenges/kaprekar-numbers
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> number_to_vector_of_digits(long long x) {
    vector<int> temp;

    if(x == 0){
        temp = {0};
        return temp;
    }

    while(x >= 1){
        temp.push_back(x % 10);
        x /= 10;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

long long vector_of_digits_to_number(vector<int> x){
    int exponent = 0;
    int i = x.size() - 1;
    long long temp  = 0;
    while(i>=0){
        temp += x[i]*pow(10,exponent);
        exponent++;

        i--;
    }
    return temp;
}


bool is_kaprekar(long long x){
    if(x == 1){
        return true;
    }
    //
    vector<int> digits = number_to_vector_of_digits((long long)(x*x));
    vector<int> digits_o = number_to_vector_of_digits(x);
    
        vector<int> lv(digits.begin(), digits.end()- digits_o.size());
        long long l = vector_of_digits_to_number(lv);
        vector<int> rv(digits.end() - digits_o.size() , digits.end());
        long long r = vector_of_digits_to_number(rv);

        if(l + r == x){
            return true;
        }
    return false;
}

int main() {
    int p,q;
    cin >> p >> q;
    int counter = 0;
    for(int i = p; i <= q; i++){
        if(is_kaprekar(i)){
            counter++;
            cout << i << " ";
        }
    }
    if(counter == 0){
        cout << "INVALID RANGE";
    }
    return 0;
}
