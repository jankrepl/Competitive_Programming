#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "Toolkit_classes.h"
#include "Toolkit_functions.h"

//Problem 44

using namespace std;

int main() {
//    Generate the first 10 000 pentagonal numbers

    vector<long> pentagonals;

    for(int i = 1; i <= 10000; i++){
        pentagonals.push_back(i*(3*i - 1)/2);
    }

//    vector<pair<int,int>> good_pairs;
    pair<long,long> winner;
    long minimum_distance = 100000000;
    winner.first = 0;
    winner.second = 0;

    for(vector<long>::iterator it = pentagonals.begin(); it < pentagonals.end();it++){
        for(vector<long>::iterator jt = it + 1; jt < pentagonals.end(); jt++){
            if((is_pentagonal(*it + *jt)) && (is_pentagonal(*jt - *it)) && ((*jt - *it) < minimum_distance)){
                winner.first = *it;
                winner.second = *jt ;
                minimum_distance = *jt - *it;
                cout << minimum_distance << endl;
            }
        }
    }

    cout << "Final minimal distance: "<< minimum_distance << endl;

}
