// Name: Encryption
// WWWW: https://www.hackerrank.com/challenges/encryption
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> best_dims(int L){
    // first coordinate is rows, seconds is columns
    int root_lower = floor(sqrt(L));
    int root_upper = ceil(sqrt(L));
    if(root_lower == root_upper){
         return make_pair(root_lower,root_lower);
    }else{
        //3 cases
        vector<int> helper = {root_lower*root_lower, root_lower*root_upper, root_upper*root_upper};
        if(helper[0] >= L){
            return make_pair(root_lower,root_lower);
            
        }else if(helper[1] >= L){
            return make_pair(root_lower,root_upper);
            
        }else{
            return make_pair(root_upper,root_upper);
        }
    }
}

int main(){
    string s;
    cin >> s;
    int L = s.size();
    pair<int,int> dimensions = best_dims(L);
    //cout << dimensions.first <<  " " << dimensions.second << endl;
    for(int j = 0; j < dimensions.second; j++){
        for(int i = 0; i < dimensions.first; i++){
            if(L <= i*dimensions.second + j){
                //pass
            }else{
                cout << s[i*dimensions.second + j];
            }      
        }
        if (j != dimensions.second - 1){
            cout << " ";
        }
    }
    return 0;
}
