// Name: Bon_Appetit
// WWWW: https://www.hackerrank.com/challenges/bon-appetit
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int meals, skipped;
    cin >> meals >> skipped;
    long total_cost;
    int cost_skipped;
        
    
    for(int i = 0; i < meals; i++){
        int temp;
        cin >> temp;
        total_cost += temp;
        
        if(i == skipped){
            cost_skipped = temp;
        }   
    }
    
    long charged;
    cin >> charged;
    
    if((total_cost - cost_skipped)/2 != charged){
        cout << charged - (total_cost - cost_skipped)/2;
    }else{
        cout << "Bon Appetit";
    }
    return 0;
}
