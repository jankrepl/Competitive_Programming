// Name: Birthday_Chocolate
// WWWW: https://www.hackerrank.com/challenges/the-birthday-bar
// Author: Jan Krepl

#include <bits/stdc++.h>

using namespace std;

int getWays(vector < int > squares, int d, int m){
    // Complete this function
    int counter = 0;
    for(int i = 0; i <= squares.size() - m; i++){
        if(accumulate(squares.begin() + i, squares.begin() + i + m, 0) == d){
            counter++;
        }
    }
    return counter;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = getWays(s, d, m);
    cout<<result<<endl;
    return 0;
}
