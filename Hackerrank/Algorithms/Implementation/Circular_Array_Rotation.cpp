// Name: Circular_Array_Rotation
// WWWW: https://www.hackerrank.com/challenges/circular-array-rotation
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

void right_circulate(vector<int> &a,int  n,int k){
    k = k % n;
        vector<int> copy = a;
        for (int i = 0; i < n; i++) {
                a[(i+k) % n] = copy[i];
        }
}

int main(){
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
    }

    right_circulate(a,n,k);

    for(int a0 = 0; a0 < q; a0++){
        int m;
        cin >> m;
        cout << a[m] << endl;
    }
    return 0;
}