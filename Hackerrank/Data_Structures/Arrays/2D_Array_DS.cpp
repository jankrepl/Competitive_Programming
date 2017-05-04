// Name: 2D_Array_DS
// WWW: https://www.hackerrank.com/challenges/2d-array
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
int get_hour_glass_sum(vector<vector<int>> &arr, int a, int b){
    // 0 <= a,b <= 3 ..we define where the top left element is located
    return (arr[a][b] + arr[a][b + 1] + arr[a][b + 2] + arr[a + 1][b + 1] + arr[a + 2][b] + arr[a + 2][b + 1] + arr[a +2][b + 2]);
}

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    
    int maxim = numeric_limits<int>::lowest();
    for(int a = 0; a <= 3; a++){
        for(int b = 0; b <= 3; b++){
            maxim = max(maxim, get_hour_glass_sum(arr, a, b));
        }
    }
    cout << maxim << endl;
    return 0;
}
