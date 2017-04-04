// Name: Taum_and_Bday
// WWWW: https://www.hackerrank.com/challenges/taum-and-bday
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
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long b;
        long w;
        cin >> b >> w;
        long x;
        long y;
        long z;
        cin >> x >> y >> z;
        long long cost_wo = b*x + w*y;
        long long cost_tc_1,cost_tc_2;
        //determine which is cheaper
 
        cost_tc_2 = (b+w)*x + w*z;
        cost_tc_1 = (b+w)*y + b*z;
    
            cout << min(min(cost_tc_1,cost_wo),cost_tc_2) << endl;
    }
    
    return 0;
}
