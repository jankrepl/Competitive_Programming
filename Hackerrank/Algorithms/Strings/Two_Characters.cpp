// Name: Two_Characters
// WWW: https://www.hackerrank.com/challenges/two-characters
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
//Lets define a function is_alt that will determine whether a certain string consist of exactly 2 characters that are
//alternating

bool is_alt(string s){
    if(s.size() <= 1){
       return false;
    }
    if(s[0] == s[1]){
        return false;
    }

    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0){
            if(s[i] != s[0]){
                return false;
            }

        }else{
            if(s[i] != s[1]){
                return false;
            }
        }
    }
    return true;
}
string extract_me(string s, char c_1, char c_2){
    string output;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c_1 || s[i] == c_2){
            output.push_back(s[i]);
        }
    }
    return output;
}
int maxLen(string s){
    // Complete this function
    //find unique characters
    set<char> s_unique(s.begin(),s.end());
    int maxxx = 0;
    for(set<char>::iterator it = s_unique.begin(); it != s_unique.end(); it++){
        for(set<char>::iterator jt = it; jt != s_unique.end(); jt++){
            if(it != jt){
                if(is_alt(extract_me(s,*it,*jt))){
                maxxx = max(maxxx,int(extract_me(s,*it,*jt).size()));
                }
            }
        }
    }
    return maxxx;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = maxLen(s);
    cout << result << endl;
    return 0;
}
