// Name: Minimum_Distances
// WWWW: https://www.hackerrank.com/challenges/minimum-distances
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
    vector<int> A(n);
    for(int i = 0; i < n; i++){
       cin >> A[i];
    }
    int solution = -1;
    bool solved = false;
    for(int dist = 1; dist < n; dist++){
        for(int i = 0; i < n - dist; i++){
            if(A[i] == A[i + dist]){
                solution = dist;
                solved = true;
            }
        }
       if(solved){
           break;
       }
    }
    
    cout << solution;
    return 0;
}
