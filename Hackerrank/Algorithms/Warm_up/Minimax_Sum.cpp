// Name: Minimax_Sum
// WWWW: https://www.hackerrank.com/challenges/mini-max-sum
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
    long int a;
    long int b;
    long int c;
    long int d;
    long int e;
    cin >> a >> b >> c >> d >> e;
    vector<int> cont;
    cont.push_back(a);
    cont.push_back(b);
    cont.push_back(c);
    cont.push_back(d);
    cont.push_back(e);
    long min_min = 10000000001;
    long max_max = 0;
    for(int i = 0; i < 5; i++ ){
        long sum = 0;
        for(int j = 0; j < 5; j++){
            if(j != i){
                sum += cont[j];
            }          
        }
        min_min = min(min_min,sum);
        max_max = max(max_max,sum);
    }
    cout << min_min << " " << max_max << endl;
}