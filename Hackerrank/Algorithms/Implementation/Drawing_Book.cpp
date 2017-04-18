// Name: Drawing_Book
// WWW: https://www.hackerrank.com/challenges/drawing-book
// Author: Jan Krepl

#include <bits/stdc++.h>

using namespace std;

int solve(int n, int p){
    // from the front
    int front = p/2;
      
    // from the back
    int back = (n-p)/2;
    return min(front, back);
}

int main() {
    int n;
    cin >> n;
    int p;
    cin >> p;
    int result = solve(n, p);
    cout << result << endl;
    return 0;
}
