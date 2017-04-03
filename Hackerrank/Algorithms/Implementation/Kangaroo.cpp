// Name: Kangaroo
// WWWW: https://www.hackerrank.com/challenges/kangaroo
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
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    
    //first kang: x1 + t*v1
    //second kang: x2 + t*v2 
    //I want the solution to be a whole number
    double solution = (double)(x1 - x2)/(v2 - v1);
    if(solution == floor(solution) && solution >= 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}
