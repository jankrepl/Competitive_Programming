// Name: Flatland_Space_Stations
// WWWW: https://www.hackerrank.com/challenges/flatland-space-stations
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
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    vector<int> sorted = c;
    sort(sorted.begin(),sorted.end());
    int max_distance = 2*sorted[0];
    for(int i = 1; i < m; i++){
        if(max_distance < sorted[i] - sorted[i - 1]){
            max_distance = sorted[i] - sorted[i - 1];
        }
    }
    if(max_distance  < 2*(n - sorted[m - 1]) - 1){
        max_distance = 2*(n - sorted[m - 1]) - 1;
    }
    cout << max_distance/2 ;
    return 0;
}
