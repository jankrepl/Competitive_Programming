// Name: Utopian_Tree
// WWWW: https://www.hackerrank.com/challenges/utopian-tree
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    int counter;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        counter = 1;
        for(int i = 1; i <= n/2; i++){
            counter = 2*counter + 1;
        }
        if(n % 2 > 0){
            counter *= 2;
        }
        cout << counter << endl;
    }
    return 0;
}


