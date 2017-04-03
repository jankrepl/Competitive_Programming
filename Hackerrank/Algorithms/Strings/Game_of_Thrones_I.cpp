// Name: Game_of_Thrones_I
// WWWW: https://www.hackerrank.com/challenges/game-of-thrones
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
   
    string s;
    cin >> s;
    //the strategy is to create a histogram and make sure for evenly sized strings that everything comes in even quantities and for evene sized strings there is exactly one odd count
    vector<int> hist(26,0);
    for(int i = 0 ; i < s.size(); i++){
        hist[(int)s[i] - 97]++;
    }
    int n_odd = 0;
    
    for(int i = 0; i < 26; i++){
        n_odd += (hist[i]%2 != 0);
    }
    bool flag = (n_odd == 0 && s.size() % 2 == 0) || ((n_odd == 1 && s.size() % 2 != 0)) ;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    if(flag == 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
