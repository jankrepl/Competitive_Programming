// Name: Repeated_String
// WWWW: https://www.hackerrank.com/challenges/repeated-string
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
    string s;
    cin >> s;
    long n;
    cin >> n;
    
    int count_initial = count(s.begin(),s.end(),'a');
    
    long long count_total = count_initial*(n/s.size()) + count(s.begin(),s.begin() + (n)%(s.size()) , 'a');
    
    cout << count_total;
    return 0;
}
