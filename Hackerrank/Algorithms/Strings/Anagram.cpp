// Name: Anagram
// WWWW: https://www.hackerrank.com/challenges/anagram
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> create_histogram(string s){
    vector<int> output(26,0);
    for(int i = 0; i < s.size(); i++){
        output[int(s[i]) - 97]++;
    }
    return output;
}

int histogram_difference(string s_1, string s_2){
    // finds the number of chages necessary to make two strings anagrams
    vector<int> h_1 = create_histogram(s_1);
    vector<int> h_2 = create_histogram(s_2);
    
    int counter = 0;
    for(int i = 0; i < 26; i++){
        counter += abs(h_1[i] - h_2[i]);
    }
    // one change will fix 2 positions in a histagram
    return counter/2;
    
}

int main() {
    // Two words are anagrams if they have the same histogram:)  
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        if(s.size() % 2 != 0){
            cout << -1 << endl;
        }else{
            string s_1 = s.substr(0, s.size()/2);
            string s_2 = s.substr(s.size()/2, s.size()/2);
            cout << histogram_difference(s_1,s_2) << endl;
        }
    }
    return 0;
}
