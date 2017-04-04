// Name: Jumping_on_the_Clouds_Revisited
// WWWW: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited
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
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    
    long energy_left = 100;
    int current_position = 0;
    
    do{
        
        current_position = (current_position + k)%n;

        energy_left -= 1;
        
        if(c[current_position] == 1){
            energy_left -= 2;
        }
        
    }while(current_position != 0);   
    cout << energy_left;
    return 0;
}
