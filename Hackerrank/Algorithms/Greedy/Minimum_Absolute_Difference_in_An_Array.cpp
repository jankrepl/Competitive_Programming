// Name: Minimum_Absolute_Difference_in_An_Array
// WWWW: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array
// Author: Jan Krepl


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    sort(a.begin(), a.end());
    int answer = 2000000000;
    for(int i = 1; i < n; i++){
        answer = min(answer, a[i] - a[i - 1]);
    }
        
    cout << answer;
    return 0;
}
