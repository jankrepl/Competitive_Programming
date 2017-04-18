// Name: Picking_Numbers
// WWW: https://www.hackerrank.com/challenges/picking-numbers
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


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    
    vector<int> hist(100,0);
    for(int i = 0; i < a.size(); i++){
        hist[a[i]]++;
    }
    
    int winner_count = 0;
    for(int i = 0; i < hist.size() - 1; i++){
        winner_count = max(winner_count, hist[i] + hist[i + 1]);
    }
    cout << winner_count;
    return 0;
}
