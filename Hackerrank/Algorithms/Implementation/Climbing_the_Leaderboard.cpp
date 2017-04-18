// Name: Climbing_the_Leaderboard
// WWW: https://www.hackerrank.com/challenges/climbing-the-leaderboard
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
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0;scores_i < n;scores_i++){
       cin >> scores[scores_i];
    }
    set<int> helper_set(scores.begin(),scores.end());
    int helper_size = helper_set.size();
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0;alice_i < m;alice_i++){
       cin >> alice[alice_i];
       pair<set<int>::iterator, bool> ins_res = helper_set.insert(alice[alice_i]);
       if(ins_res.second){
           cout << helper_size + 1 - distance(helper_set.begin(), ins_res.first) << endl;
           helper_set.erase(alice[alice_i]);
       } else{
           cout << helper_size - distance(helper_set.begin(), ins_res.first) << endl;
       }
           
    }

    
    return 0;
}
