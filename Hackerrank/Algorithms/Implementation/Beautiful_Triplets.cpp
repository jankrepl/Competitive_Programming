// Name: Beautiful_Triplets
// WWWW: https://www.hackerrank.com/challenges/beautiful-triplets
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define loop(i,lb,ub) for(int i = lb; i < ub; i++ )

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a[i] = temp;
    }
    
    long counter = 0;
    
    loop(i,0,n){
        loop(j,i+1,n){
            if(a[j] - a[i] > d){
                break;
            }
            loop(k,j+1,n){
                if(a[k] - a[j] > d){
                break;
            }
                if(a[k] - a[j] == d && a[j] - a[i] == d )   {
                    counter++;
                }
            }
        }
    }
    cout << counter;
    return 0;
}
