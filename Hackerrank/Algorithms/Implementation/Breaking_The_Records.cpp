// Name: Breaking_The_Records
// WWWW: https://www.hackerrank.com/challenges/breaking-best-and-worst-records
// Author: Jan Krepl

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long> score(n);
    vector<long> lows(n);
    vector<long> highs(n);
    cin >> score[0];
    highs[0] = score[0];
    lows[0] = score[0];
    int c_l = 0;
    int c_h = 0;

    for(int score_i = 1; score_i < n; score_i++){
       cin >> score[score_i];
       highs[score_i] =  max(score[score_i],highs[score_i - 1]);
       if(highs[score_i] > highs[score_i - 1]){
           c_h++;
       }
        
       lows[score_i] =  min(score[score_i],lows[score_i - 1]);
        if(lows[score_i] < lows[score_i - 1]){
           c_l++;
       }
        
    }
    cout << c_h << " " << c_l << endl;
    return 0;
}