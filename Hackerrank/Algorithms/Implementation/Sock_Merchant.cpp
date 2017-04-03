// Name: Sock_Merchant
// WWWW: https://www.hackerrank.com/challenges/sock-merchant
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
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    
    //We will add the socks consecutively into a set..as soon as we insert is not done..a pair is found and 
    //the existing number will be deleted
    
    int counter = 0;
    set<int> pairs;
    
    for(int i = 0; i < n; i++){
        pair<set<int>::iterator, bool> eval = pairs.insert(c[i]);
        if(!eval.second){
            pairs.erase(eval.first);
            counter++;
        }
        
    }    
    cout << counter;
    return 0;
}
