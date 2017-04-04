// Name: Manesa_and_Stones
// WWWW: https://www.hackerrank.com/challenges/manasa-and-stones
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        int n,a,b;
        cin >> n >> a >> b;
        set<int> results;
        
        int index = 0;
        while(index < n){
            results.insert(a*index + b*(n - index - 1));
            index++;
        }
        for(set<int>::iterator i = results.begin(); i != results.end(); i++){
            cout << *i <<" "; 
        }
        cout << endl;
    }
    return 0;
}
