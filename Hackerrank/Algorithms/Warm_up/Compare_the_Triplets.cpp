// Name: Compare_the_Triplets
// WWWW: https://www.hackerrank.com/challenges/compare-the-triplets
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
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    
    int alice_points = 0;
    int bob_points = 0;
    
    vector<int> alice({a0,a1,a2});
    vector<int> bob({b0,b1,b2});
    
    
    int index = 0;
    
    while(index <= 2){
        if(alice[index] > bob[index]){
            alice_points++;
            
        }else if(alice[index] < bob[index]){
               bob_points++;
        }else{
            //do nothing
        }
        
        index++;
    }
    
    cout << alice_points << " " << bob_points;
    return 0;
}