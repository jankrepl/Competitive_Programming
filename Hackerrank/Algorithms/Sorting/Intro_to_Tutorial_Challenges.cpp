// Name: Intro_to_Tutorial_Challenges
// WWWW: https://www.hackerrank.com/challenges/tutorial-intro
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    int value,n;
    cin >> value >> n;
    
    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << distance(a.begin(),find(a.begin(),a.end(), value));
    return 0;
}
