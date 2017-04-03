// Name: Super_Reduced_String
// WWWW: https://www.hackerrank.com/challenges/reduced-string
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<string,bool> reduce_me(string s){
    string output_s = s;
    bool output_b = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == s[i+1]){
            output_s.replace(i,2,"");
            output_b = true;
            break;
        }
    }
    return make_pair(output_s,output_b);
}

int main() {
    string my_string;
    cin >> my_string;
    bool reducable = reduce_me(my_string).second;
    while(reducable){
        my_string = reduce_me(my_string).first;
        reducable = reduce_me(my_string).second;
    };
    if(my_string.empty()){
        cout << "Empty String";
    }else{
            cout << my_string;
        
    }
    return 0;
}
