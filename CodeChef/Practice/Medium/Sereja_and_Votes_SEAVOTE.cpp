// Name: Sereja_and_Votes 
// Problem_Code: SEAVOTE
// WWW: https://www.codechef.com/problems/SEAVOTE
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <assert.h>
#include <cstring>

using namespace std;



pair<int,int> sum_me(vector<int> &A){
    // sum vector and count the number of nonzero elements:)
    int res = 0;
    int counter_nonzero = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i] != 0){
            res += A[i];
            counter_nonzero++;
        }
    }
    return make_pair(res, counter_nonzero);
}





int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> B(N);
        for(int i = 0; i < N; i++){
            cin >> B[i];
        }

        // algorithm
        pair<int,int> zipped = sum_me(B);
        int summa_B = zipped.first;
        N = zipped.second;

        if(summa_B == 100){
            cout << "YES" << endl;
            continue;
        }else if(summa_B < 100){
            // summa_B >= summa_A
            cout << "NO" << endl;
            continue;

        }else if(summa_B  >= 100 + N){
            // note the upper limit on how B_i can differ from A_i is 1 (non inclusive) 
            // therefore it must hold that 100 = summa_A > summa_B - number_of_nonzero_elements ..
            
            cout << "NO" << endl;
            continue;
        }else{
            //clarly
            cout << "YES" << endl;
        }

    }

}