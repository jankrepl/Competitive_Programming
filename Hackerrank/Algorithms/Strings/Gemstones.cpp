// Name: Gemstones
// WWWW: https://www.hackerrank.com/challenges/gem-stones
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_two(int n){
    return n == 2;
}

int main() {
    int T;
    cin >> T;
    vector<int> common(26, 2);
    while(T--){
        string s;
        cin >> s;
        vector<int> histogram(26, 0);
        for(int i = 0; i < s.size(); i++){
            if(histogram[(int)s[i] - 97] == 0){
                histogram[(int)s[i] - 97] = 1;
            }
            if(histogram[(int)s[i] - 97] == 1){
                histogram[(int)s[i] - 97] = 2;
            }   
        }
        for(int i = 0; i < 26; i++){
            if(histogram[i] == 2 && common[i] == 2){
                common[i] = 2;
            }else{
                common[i] = 0;
            }
        }

    }
    int result = count_if(common.begin(),common.end(),is_two);
         cout << result << endl;
}
