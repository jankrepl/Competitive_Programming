// Name: The_LoveLetter_Mystery
// WWWW: https://www.hackerrank.com/challenges/the-love-letter-mystery
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
    while(T--){
        string s;
        cin >> s;
        int counter = 0;
        for(int i = 0; i <= s.size()/2 - 1; i++){
            counter += abs(int(s[i]) - int(s[s.size()- i - 1]));  
        }
        cout << counter << endl;
    }
    return 0;
}
