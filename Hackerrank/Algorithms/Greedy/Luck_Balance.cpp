// Name: Luck_Balance
// WWWW: https://www.hackerrank.com/challenges/luck-balance
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,K;
    cin >> N >> K;
    vector<int> importants;
    vector<int> unimportants;
    for(int i = 1; i <= N; i++){
        int L,stat;
        cin >> L >> stat;
        if(stat == 0){
            unimportants.push_back(L);
        }else{
            importants.push_back(L);
        }
    }
    
    sort(importants.begin(),importants.end());
    if(K > importants.size()){
        K = importants.size();
    }
    int answer = accumulate(unimportants.begin(),unimportants.end(),0) 
        + accumulate(importants.end() - K ,importants.end(),0) 
        - accumulate(importants.begin(), importants.end() - K, 0);
    
    cout << answer << endl;
    return 0;
}
