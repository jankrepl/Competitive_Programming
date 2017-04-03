// Name: Between_Two_Sets
// WWWW: https://www.hackerrank.com/challenges/between-two-sets
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
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    
    int counter = 0;
    
    for(int i = 1; i <= 100; i++){
         bool fail = false;
        for(vector<int>::iterator jt = a.begin(); jt < a.end(); jt++){
            if(i%(*jt) != 0){
                fail = true;
                break;
            }   
        }
        for(vector<int>::iterator mt = b.begin(); mt < b.end(); mt++){
            if((*mt%i) != 0){
                fail = true;
                break;
            }   
        }
        if(!fail){
        counter++;
        }
    }
        
    cout << counter;
    return 0;
}
