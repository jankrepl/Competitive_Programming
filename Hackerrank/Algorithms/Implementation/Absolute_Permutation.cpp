// Name: Absolute_Permutation
// WWWW: https://www.hackerrank.com/challenges/absolute-permutation
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

void print_me(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        //create vector
        vector<int> v(n,0);
        for(int i = 1; i<=n; i++){
            v[i-1] = i;
        }
        // create its dominant vector - ith element = v[i] - k if possible..if not possible v[i] + k ..and if not possible 
        //we fail
        vector<int> dominant(n,0);
        vector<int> available_bank(n,1); // ab[i] == 1 means that i+1 is available ab[i] == 0 means that its not
        bool fail = false;
        for(int i = 0; i < n; i++){
            if(v[i] - k > 0 && available_bank[v[i]-k -1]){
                dominant[i] = v[i] - k;
                available_bank[v[i]-k - 1] = 0;
                continue;
            }else if(v[i] + k <= n  && available_bank[v[i] + k - 1]){
                dominant[i] = v[i] + k;
                available_bank[v[i] + k - 1] = 0;
                continue;
            }else{
                fail = true;
                
            }
        }
        if(fail){
            cout << "-1" << endl;
        }else{
            print_me(dominant);
        }

        
    }
    
    return 0;
}
