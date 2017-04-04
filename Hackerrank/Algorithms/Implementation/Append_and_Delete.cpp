// Name: Append_and_Delete
// WWWW: https://www.hackerrank.com/challenges/append-and-delete
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
#include <stdio.h>
#include <string.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    
    //first find a character until which the two strings are the same
    int the_same_limit = 0;
    int i = 0;
    while(s[i] == t[i]){
        the_same_limit++;
        i++;
    }
    
    if(s.substr(1,t.size()) == t && s.size() - t.size() <= k){
        cout << "Yes";
        return 0;
    }
    int size_s_different = s.size() - the_same_limit;
    int size_t_different = t.size() - the_same_limit;
    
    int ops = size_s_different + size_t_different;
    if(ops/(k*1.0) <= 1 && (ops%k) % 2 == 0){
        cout << "Yes";   
    }else{
        cout << "No";
    }

    return 0;
}
