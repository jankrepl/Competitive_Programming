// Name: Ceasar_Cipher
// WWWW: https://www.hackerrank.com/challenges/caesar-cipher-1
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_letter(char c){
    return (((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122));
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    for(int i = 0; i < n; i++){
        if(is_letter(s[i])){
            if((int )s[i] >= 97){
                s[i] = (char)(((((int)s[i] + k) - 97) % 26) + 97);
                
            }else{
                s[i] = (char)(((((int)s[i] + k) - 65) % 26) + 65);
                
            }
        }
    }
    cout << s;
    return 0;
}
