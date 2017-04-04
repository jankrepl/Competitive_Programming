// Name: Jumping_on_the_Clouds
// WWWW: https://www.hackerrank.com/challenges/jumping-on-the-clouds
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
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    
    int current_position = 0;
    int counter = 0;
    
    while(current_position < n - 1){
        if(c[current_position + 2] == 0){
            current_position += 2;
        }else{
            current_position += 1;
        }
        counter++;
    }
    cout << counter;
    return 0;
}
