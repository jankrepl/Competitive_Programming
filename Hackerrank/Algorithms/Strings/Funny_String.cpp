// Name: Funny_String
// WWWW: https://www.hackerrank.com/challenges/funny-string
// Author: Jan Krepl


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_funny(string s){
    string reversed = s;
    reverse(reversed.begin(),reversed.end());
    
    for(int i = 1; i < s.size(); i++){
        if(abs((int)(s[i] - s[i - 1])) != abs((int)(reversed[i] - reversed[i - 1])) ){
            return false;
        }
        
    }
    
    return true;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; i++){
        string s;
        cin >> s;
        if(is_funny(s)){
            cout << "Funny" << endl;
        }else{
            cout << "Not Funny" << endl;
        }
    }
    return 0;
}
