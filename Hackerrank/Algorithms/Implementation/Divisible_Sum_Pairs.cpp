// Name: Divisible_Sum_Pairs
// WWWW: https://www.hackerrank.com/challenges/divisible-sum-pairs
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
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int counter = 0;
    for(auto it = a.begin(); it < a.end(); it++){
        for(auto jt = it + 1; jt < a.end(); jt++){
            if((*it + *jt) % k ==0){
                counter++;
            }
        }
    }
    cout << counter;
    return 0;
}
