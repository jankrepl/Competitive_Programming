// Name: Sequence_Equation
// WWWW: https://www.hackerrank.com/challenges/permutation-equation
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
    int N;
    cin >> N;
    vector<int> a(N+1);
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= N; i++){
        cout << int(find(a.begin(),a.end(),int(find(a.begin(),a.end(),i) - a.begin())) - a.begin()) << endl;
    }
    return 0;
}
