// Name: Sherlock_and_Anagrams
// WWWW: https://www.hackerrank.com/challenges/sherlock-and-anagrams
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<string> create_all_substrings(string s, int length){
    vector<string> output;
    for(int i = 0; i <= s.size() - length; i++){
        output.push_back(s.substr(i,length));
    }
    return output;
}

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


bool are_anagrams(string s_1, string s_2){
    return (histogram_difference(s_1,s_2) == 0);
}

int find_all_anagrams(vector<string> vs){
    //
    int counter = 0;
    for(int i = 0; i < vs.size(); i++){
        for(int j = i + 1; j < vs.size(); j++){
            if(are_anagrams(vs[i],vs[j])){
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int counter = 0;
        for(int length = 1; length < s.size(); length++){
            vector<string> vs = create_all_substrings(s,length);
            counter += find_all_anagrams(vs);
        }
        cout << counter << endl;
    }
    return 0;
}
