// Name: Sherlock_and_Array
// WWWW: https://www.hackerrank.com/challenges/sherlock-and-array
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
       int n;
        cin >> n;
       	vector<int> a(n);
        vector<long> ca(n,0);
        cin >> a[0];
        ca[0] = a[0];
        for(int i = 1; i < n; i++){
            cin >> a[i];
            ca[i] = ca[i - 1] + a[i];
        }
                if(a.size() == 1 || a.front() == a.back()){
            cout << "YES" << endl;
                    continue;
        }
        bool suc = false;
        long l,r;
        for(int i = 1; i < n; i++){
            l = ca[i - 1];
            r = ca.back() - ca[i];
            if(l == r){
                cout << "YES" << endl;
                suc = true;
                break;
            }
        }
        if(!suc){
            cout << "NO" << endl;}

    }
    
    return 0;
}