// Name: ACM_ICPC_Team
// WWWW: https://www.hackerrank.com/challenges/acm-icpc-team
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    
    int winner = -1;
    int counter = -1;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int pair_cum = 0;
            for(int k = 0; k < m; k++){
               pair_cum += ((int)topic[i][k] - 48) | ((int)topic[j][k] - 48);
            }
            if(pair_cum > winner){
                winner = pair_cum;
                counter = 1;
            }else if(pair_cum == winner){
                counter++;
            }else{
                
            }     
        }
    }
    cout << winner << endl << counter;
    return 0;
}
