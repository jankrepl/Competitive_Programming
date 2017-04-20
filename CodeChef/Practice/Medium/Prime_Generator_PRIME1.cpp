// Name: Prime_Generator_PRIME1
// Problem_Code: PRIME1
// WWWW: https://www.codechef.com/problems/PRIME1
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

typedef unsigned int uint;

// We will combine both a sieve and is_prime function

uint sieve_upper_limit = 20000000;
vector<bool> sieve(1000000001,true);


void populate_sieve(int upper_limit){
    sieve[0] = false;
    sieve[1] = false;
    for(uint i = 2; i <= upper_limit; i++){
        if(sieve[i]){
            uint multiplier = 2;
            while(multiplier * i <= upper_limit){
                sieve[multiplier * i] = false;
                multiplier++;
            }
        }
    }
}

bool is_prime(uint a){
    if(a < sieve_upper_limit){
        return sieve[a];
    }else{
        if(a % 2 == 0){
            return false;
        }
        for(uint i = 3; i*i <= a; i += 2){
            if(a % i == 0){
                return false;
            }
        }
        return true;
    }
}

int main(){
populate_sieve(sieve_upper_limit);
    int t;
    cin >> t;
    while(t--){
        uint m,n;
        cin >> m >> n;
        for(int i = m; i <= n; i++){
            if(is_prime(i)){
                cout << i << endl;
            }
        }
        cout << endl;
    }
}

    