// Name: Bigger is Greater
// WWWW: https://www.hackerrank.com/challenges/bigger-is-greater
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
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        bool status;
        status = next_permutation(s.begin(),s.end());
        if(!status){
            cout << "no answer" << endl;
        }else{
            cout << s << endl;      
        }
    }
}
