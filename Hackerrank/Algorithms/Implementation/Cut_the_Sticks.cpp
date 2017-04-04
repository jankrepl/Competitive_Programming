// Name: Cut_the_Sticks
// WWWW: https://www.hackerrank.com/challenges/cut-the-sticks
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> cut_me(vector<int> v){
    vector<int> result;
    vector<int>::iterator minimum_it = min_element(v.begin(),v.end());
    for(int i = 0; i < v.size();i++){
        if(v[i]!= *minimum_it){
            result.push_back(v[i] - *minimum_it);
        }
    }
    return result;

}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
    }

    while(arr.size() >= 1){
        cout << arr.size() << endl;;
        arr = cut_me(arr);
    }
    return 0;
}


