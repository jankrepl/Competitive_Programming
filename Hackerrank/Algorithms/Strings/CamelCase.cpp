// Name: CamelCase
// WWWW: https://www.hackerrank.com/challenges/camelcase
// Author: Jan Krepl

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool is_upper_case(char c){
    return ((int)c <= 90 && (int)c >= 65);
}


int main(){
    string s;
    cin >> s;
    int counter = 1; //one word always
    for(int i = 0; i < s.size(); i++){
        if(is_upper_case(s[i])){
            counter++;
        } 
    }
    cout << counter;
    
    return 0;
}
