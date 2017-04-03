// Name: Lonely_Integer
// WWWW: https://www.hackerrank.com/challenges/lonely-integer
// Author: Jan Krepl



#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int lonelyinteger(vector < int > a) {
    for(int i = 0; i < a.size(); i++){
        bool has_found = false;
        for(int j = 0; j < a.size(); j++){
            if(i != j && a[i] == a[j]){
                has_found = true;
                break;
            }
        }
        if(has_found){
            continue;
        }else{
            return a[i];
        }
    }
    return 0;
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i < _a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}
