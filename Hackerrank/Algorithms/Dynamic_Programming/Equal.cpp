// Name: Equal
// WWWW: https://www.hackerrank.com/challenges/equal
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long my_function(long n){
    //We count the minimal number of operations to get from number n to 0 by 5,2,1 decremenets
    return n/5 +(n % 5)/2 + (n % 5) % 2;
}

int main(){
    long T,n;
    cin >> T;
    for (long i = 1; i <= T; i++){
        cin >> n;
        vector<long> coll(n,0);
        int minimum = 1000000;
        //read input colleagues
        for(int m = 0; m < n; m++){
            cin >> coll[m];
            if(coll[m] < minimum){
                minimum = coll[m];
            }
        }
        vector<long> final(6,0);
        for(int j = 0; j <= 5; j++){
            for(int c = 0; c < n; c++){
                final[j] += my_function(abs(coll[c] - minimum + j));

            }
        }
        vector<long>::iterator result_it = min_element(final.begin(),final.end());
        cout << *result_it << endl;
    }
}