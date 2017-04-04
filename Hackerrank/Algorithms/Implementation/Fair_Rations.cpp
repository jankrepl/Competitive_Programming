// Name: Fair_Rations
// WWWW: https://www.hackerrank.com/challenges/fair-rations
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
    int N;
    cin >> N;
    vector<int> B(N);
    for(int B_i = 0;B_i < N;B_i++){
       cin >> B[B_i];
    }
    int sum = accumulate(B.begin(),B.end(),0);
    
    int counter = 0;
    if(sum % 2 != 0){
        cout << "NO" << endl;
    }else{
        for(int i = 0; i < N; i++){
            if(B[i] % 2 != 0){
                B[i]++;
                if(i+1 < N){
                    B[i+1]++;                
                }
                counter += 2;
            }
        }
            cout << counter << endl;
    }
    
    //we will just use a necessary condition for check in..and that is the entire sum is even
    
    return 0;
}
