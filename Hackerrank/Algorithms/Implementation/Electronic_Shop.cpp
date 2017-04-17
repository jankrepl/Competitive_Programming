// Name: Electronic_Shop
// WWWW: https://www.hackerrank.com/challenges/electronics-shop
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
    int s;
    int n;
    int m;
    cin >> s >> n >> m;
    vector<int> keyboards(n);
    for(int keyboards_i = 0;keyboards_i < n;keyboards_i++){
       cin >> keyboards[keyboards_i];
    }
    vector<int> pendrives(m);
    for(int pendrives_i = 0;pendrives_i < m;pendrives_i++){
       cin >> pendrives[pendrives_i];
    }
    int maximum = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(keyboards[i] + pendrives[j] <= s){
                maximum = max(maximum, keyboards[i] + pendrives[j]);
            }
        }
    }
    cout << maximum;
    return 0;
}
