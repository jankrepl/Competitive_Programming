// Name: Making_Anagrams
// WWWW: https://www.hackerrank.com/challenges/making-anagrams
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    // the idea here is to create histograms of both and then just do their absolute difference
    
    string s,t;
    cin >> s >> t;
    vector<int> his(26,0),hit(26,0),res(26,0);
    for(int i = 0; i < s.size(); i++){
        his[(int)s[i] - 97]++;
    }
    
     for(int i = 0; i < t.size(); i++){
        hit[(int)t[i] - 97]++;
    }
    
    for(int i = 0; i < 26; i++){
        res[i] = abs(hit[i] - his[i]);
    }
    int result = accumulate(res.begin(),res.end(),0);
    cout << result;
    return 0;
}
