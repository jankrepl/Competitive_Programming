// Name: Priyanka_and_Toys
// WWWW: https://www.hackerrank.com/challenges/priyanka-and-toys
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {  
    int N;
    cin >> N;
    vector<int> w(N);
    for(int i = 0; i < N; i++){
        cin >> w[i];
    }
    sort(w.begin(), w.end());
    int counter = 1;
    /* Strategy */
    // We will just go from left to the right...
    int lw = w[0];
    int uw = lw + 4;
    for(int i = 0; i < N; i++){
        if(w[i] <= uw){
            continue;
        }else{
            lw = w[i];
            uw = lw + 4;
            counter++;
        }
    }
    cout << counter << endl;
}


