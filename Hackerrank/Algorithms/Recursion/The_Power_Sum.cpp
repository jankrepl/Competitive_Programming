// Name: The_Power_Sum
// WWW: https://www.hackerrank.com/challenges/the-power-sum
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
#include <assert.h>


using namespace std;

/* Strategy */
// Backsolve - imagine we are give a sequence a_1,.._a_t (ordered from the biggest to the smallest)
// such that a_1^N + ... + a_t^N = X
// THEN it must hold true that X - a_t^N - ... - a_1^n = 0;
// this gives a clear idea for a recursion ... we recursively subtract all possible numbers from X
// if the result does not give zero .. its not the solition

int solver(int X, int N, int previous_a = 0) {
    int counter = 0;

    bool no_kids = true;
    for (int i = previous_a + 1; pow(i, N) <= X; i++) {
        counter += solver(X - pow(i, N), N, i);
        no_kids = false;
    }

    if(no_kids && X == 0){
        return counter + 1;
    }else{
        return counter;
    }

}


int main() {
    int X, N;
    cin >> X >> N;
    cout << solver(X, N, 0);

}


