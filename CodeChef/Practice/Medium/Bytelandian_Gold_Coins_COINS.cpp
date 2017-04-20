// Name: Bytelandian_Gold_Coins_COINS
// Problem_Code: COINS
// WWWW: https://www.codechef.com/problems/COINS
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility> 
#include <map>


using namespace std;

// memoization table
map<unsigned int,unsigned int> table;

unsigned int coin_highest_value(unsigned int n){
    //finds out the maximum amount of money a given coin can make

    //check if in memo table contains n
    map<unsigned int,unsigned int>::iterator it = table.find(n);
    if(it != table.end()){
        return it->second;
    }

    if(n >= n/4 + n/3 + n/2){
        //base case
        table.insert(pair<unsigned int,unsigned int>(n,n));
        return n;
    }else{
        //induction case  
        table.insert(pair<unsigned int,unsigned int>(n, coin_highest_value(n/4) + coin_highest_value(n/3) + coin_highest_value(n/2)));
        return table[n];
    }
}


int main(){
    unsigned int n;
    while(cin >> n){
        if(n == 0){
            cout << 0 << endl;
        }else{
            cout << coin_highest_value(n) << endl;   
        }

    }
}

    