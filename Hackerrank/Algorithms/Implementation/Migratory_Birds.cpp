// Name: Migratory_Birds
// WWWW: https://www.hackerrank.com/challenges/migratory-birds
// Author: Jan Krepl

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> types(n);
    vector<int> counter(6,0);
    for(int types_i = 0; types_i < n; types_i++){
       cin >> types[types_i];
       counter[types[types_i]]++;
    }
    int result = distance(counter.begin(), max_element(counter.begin(),counter.end())); //always points at the first 
    cout << result;
}
