// Name: Alternating_Characters
// WWWW: https://www.hackerrank.com/challenges/alternating-characters
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string s;
        cin >> s;
        int counter = 0;
        for(int j = 1; j < s.size(); j++){
            if(s[j] == s[j-1]){
                counter++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}
