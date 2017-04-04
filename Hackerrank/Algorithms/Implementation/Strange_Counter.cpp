// Name: Strange_Counter
// WWWW: https://www.hackerrank.com/challenges/strange-code
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


int main() {

    long long t;
    cin >> t;

    vector<long long> my_counter({1});

    //index represents the number of times to which 3 must be taken

    long long step = 3;

    while(my_counter.back() <= t){
        my_counter.push_back(my_counter.back() + step );
        step *= 2;
    }

    //second last row now is the starting index si
    //determine counter(si)
    long long counter_si = 3*pow(2,distance(my_counter.begin(),my_counter.end() - 2));
    long long difference = t - *(my_counter.end() - 2);
    long long result = counter_si - difference;
//    long long first = *(my_counter.end() - 2)*distance(my_counter.begin(),my_counter.end() - 2)*3;
//    long long dist = t - *(my_counter.end() - 2);
//
//    long long result = first - dist;
   cout << result;
    return 0;
}

