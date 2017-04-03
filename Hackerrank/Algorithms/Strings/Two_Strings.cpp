// Name: Two_Strings
// WWWW: https://www.hackerrank.com/challenges/game-of-thrones
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
    for(int m = 0; m < T; m++){
        string a,b;
        cin >> a >> b;
        vector<int> hist_a(26,0), hist_b(26,0);
        for(int i = 0; i < a.size(); i++){
            if(hist_a[int(a[i]) - 97] == 0){
                hist_a[int(a[i]) - 97] = 1;
            }
        }
        for(int i = 0; i < b.size(); i++){
            if(hist_b[int(b[i]) - 97] == 0){
                hist_b[int(b[i]) - 97] = 1;
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(( hist_a[i] == 1) && (hist_b[i] == 1)){
                cout << "YES" << endl;
                goto jump;
            }
        }
        cout << "NO" << endl;
        jump:;
    }
        
}

