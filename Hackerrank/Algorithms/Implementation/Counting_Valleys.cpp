// Name: Counting_Valleys
// WWWW: https://www.hackerrank.com/challenges/counting-valleys
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int current_level = 0;
    int previous_level = 0;
    int counter_valley = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'D'){
            current_level--;
        }else{
            current_level++;
        }

        if(current_level < 0 && previous_level == 0){
            counter_valley++;
        }
        previous_level = current_level;
    }
    cout << counter_valley;
}
