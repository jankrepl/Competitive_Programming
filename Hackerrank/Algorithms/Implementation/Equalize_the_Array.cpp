// Name: Equalize_the_Array
// WWWW: https://www.hackerrank.com/challenges/equality-in-a-array
// Author: Jan Krepl

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {  
    int size;
    cin >> size;
    
    vector<int> array;
    set<int> unique;
    //goal is two the maximum occurances of the same elements find the number of times a
    for(int i = 0; i < size; i++){
        int temp;
        cin >> temp;
        array.push_back(temp);
        unique.insert(temp);
    }
    int max_occur = 0;
    
    for(auto it = unique.begin(); it != unique.end(); it++){
        int counter = 0;
        for(auto jt = array.begin(); jt < array.end(); jt++){
            if(*jt == *it){
                counter++;
            }
        }
        max_occur = max(max_occur,counter);
    }
    
    cout<< size - max_occur;
    return 0;
}
