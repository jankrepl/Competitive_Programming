// Name: Maximizing_XOR
// WWWW: https://www.hackerrank.com/challenges/maximizing-xor
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


int maxXor(int l, int r) {
    int maximum = 0;
    
    for(int i = l; i <= r; i++){
        //b^b = 0..so we can save some time below
        for(int j = i + 1; j <= r; j++){
            if(maximum < (i^j)){
                maximum = (i^j);

            }
        }
    }
    return maximum;
    
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
