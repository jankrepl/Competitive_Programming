// Name: String_Construction
// WWWW: https://www.hackerrank.com/challenges/string-construction
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

bool can_use_substring(string goal, string current){
    //find next letter
    string next_letter = goal.substr(current.size(),1);
    return (current.find(next_letter) != string::npos);
}

int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string s;
        cin >> s;
        int counter = 0;
        for(int i = 0; i < s.size(); i++){
            string current = s.substr(0,i);
            if(!can_use_substring(s,current)){
                counter++;
            }
        }
        cout << counter << endl ;
    }
    return 0;
}

