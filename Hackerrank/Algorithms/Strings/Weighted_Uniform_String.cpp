// Name: Weighted_Uniform_String
// WWWW: https://www.hackerrank.com/challenges/weighted-uniform-string
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


int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    vector<int> counter(27,0); //ith ...we leave 0th element empty for easy
    vector<int> counter_temp(27,0);
   
    for(long i = 0; i < s.size(); i++){
        counter_temp.at((s[i] - 96))++;
        
        if(i+1 == s.size() || s[i]!=s[i+1]){//last fu
           counter.at((s[i] - 96)) = max(counter.at((s[i] - 96)),counter_temp.at((s[i] - 96)));
           counter_temp.at((s[i] - 96)) = 0;
        }
    }
    //create their weights
    for(vector<int>::iterator it = counter.begin()+1; it < counter.end();it++){
        *it *= distance(counter.begin(),it);
    }

    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        
        if(x > 2600000){
            cout << "No" << endl;
            continue;
        }
        // your code goes here
        for(vector<int>::iterator it = counter.begin()+1; it < counter.end();it++){
            if((x <= *it) && (x % distance(counter.begin(),it)) == 0){
                cout << "Yes" << endl;
                break;
            }
            if(it == counter.end() - 1){
                cout << "No" << endl;
                break;
            }
        }
    }
    return 0;
}
