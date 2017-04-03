// Name: Beautiful_Days_at_the_Movies
// WWWW: https://www.hackerrank.com/challenges/the-hurdle-race
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reverse_me(int orig){
    int ans = 0;

    while(orig > 0)
    {
        ans *= 10;
        ans += orig % 10;
        orig /= 10;
    }
    return ans;
}

bool is_beautiful(int x, long k){
    return !(abs(reverse_me(x)-x)%k);
}

int main() {
    int lower,upper,k;
    cin >> lower >> upper >> k;
    
    int counter = 0;
    for(int i = lower; i <= upper; i++){
        if(is_beautiful(i,k)){
            counter++;
        }
    }
    cout << counter;
    return 0;
}
