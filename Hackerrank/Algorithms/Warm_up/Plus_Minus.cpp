// Name: Plus_Minus
// WWWW: https://www.hackerrank.com/challenges/plus-minus
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    long counter_zeros = 0;
    long counter_positive = 0;
    long counter_negative = 0;
    
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
        if(arr[arr_i] > 0 ){
            counter_positive++;
        }else if(arr[arr_i] == 0){
            counter_zeros++;
        }else{
            counter_negative++;
        }
    }
    
    
    double zeros = (counter_zeros * 1.0)/n;
    double pos = (counter_positive * 1.0)/n;
    double neg = (counter_negative * 1.0)/n;
    printf("%1.6f\n", pos);
    printf("%1.6f\n", neg);
    printf("%1.6f\n", zeros);

}
