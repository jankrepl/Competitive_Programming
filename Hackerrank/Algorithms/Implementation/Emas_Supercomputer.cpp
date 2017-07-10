// Name: Ema's Supercomputer
// WWW: https://www.hackerrank.com/challenges/two-pluses
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
#include <unordered_map>
#include <assert.h>
#include <cstring>
#include <typeinfo>
#include <cstring>
#include <queue>
#include <bitset>
#include <tuple>

using namespace std;

// Extremely brute force approach
// idle position is -1
// Step 0: sort pairs of numbers 1,3,...min(n,m) (<- all possible cross sizes) by their products .. 
// Step 1: Write a find_cross function .. set of all possible crosses with a given length 
// Step 2: Run the above function for cross_size = 1, 3, 5, 7, 9, ... min(n,m) and save into a map:D
// Step 3: Pair by pair investigate whether a correspodning database of crosses of a given size are not
// overlapping...as soon as thats the case, stop the program and output the result


void print_me(vector< vector<int> > a){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}



bool not_overlapping(vector<vector<int>> a, vector<vector<int>> b){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] == -1 && b[i][j] == -1){
                return false;
            }
        }
    }

    return true;
}




vector<vector<int>> create_cross(vector<vector<int>> &field, int c_x, int c_y, int cross_size){
    //horizontal sum
    vector<vector<int>> output = field;
    output[c_x][c_y] = -1; // center 

    for(int i = -cross_size/2; i <= cross_size/2; i++){
        if(i == 0){
            continue;
        }
        output[c_x][c_y + i] = -1;
    }

    // vertical sum
    for(int i = -cross_size/2; i <= cross_size/2; i++){
        if(i == 0){
            continue;
        }
        output[c_x + i][c_y] = -1;
    }

    return output;

}


set<vector<vector<int>>> find_cross(vector<vector<int>> &field, int cross_size){
    int n = field.size();
    int m = field[0].size();

    set<vector<vector<int>>> output;
    bool status = false;

    // loop through possible centers and check if horizontal and vertical sum == cross_size (since we
    // encoded goods with 0s)
    for(int c_x = cross_size/2; c_x < n - cross_size/2; c_x++){
        for(int c_y = cross_size/2; c_y < m - cross_size/2; c_y++){
            if(field[c_x][c_y] == 0){
                continue;
            }
            //horizontal sum
            int h_sum = 1;
            for(int i = -cross_size/2; i <= cross_size/2; i++){
                if(i == 0){
                    continue;
                }
                h_sum += field[c_x][c_y + i];
            }
            if(h_sum != cross_size){
                continue;
            }

            // vertical sum
            int v_sum = 1;
            for(int i = -cross_size/2; i <= cross_size/2; i++){
                if(i == 0){
                    continue;
                }
                v_sum += field[c_x + i][c_y];
            }
            if(v_sum != cross_size){
                continue;
            }

            // all passed...its a cross ..u need to pad it with - ones 
            output.insert(create_cross(field,c_x,c_y,cross_size));

        }
    }





    return output;

}

// lower of equal operator
bool comp(pair<int,int> &a, pair<int,int> &b){
        return a.first * a.second <= b.first * b.second;
}



int main(){

    // Read in the matrix - encoding bad as 0 and good as 1
    int n,m;
    cin >> n >> m;
    vector< vector<int> > a(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp;
            cin >> temp;
            a[i][j] = (temp == 'G' ? 1 : 0);
        }
    }


    // create vector of possible sizes
    int ub = min(n,m);
    vector<int> possible_sizes;
    int value = 1;
    while(value <= ub){
        possible_sizes.push_back(value);
        value += 2;
    }

    // create a map that to each pair of possible sizes assigns a product
    vector<pair<int,int>> my_pairs;
    for(int i = 0; i < possible_sizes.size(); i++){
        for(int j = 0; j <= i; j++){
            my_pairs.push_back(make_pair(possible_sizes[i], possible_sizes[j]));
        }
    }

    sort(my_pairs.rbegin(), my_pairs.rend(), comp);


    // Save crosss of different sizes 
    unordered_map<int, set<vector<vector<int>>>> database;
    for(int i = 0; i < possible_sizes.size();i++){
        database[possible_sizes[i]] = find_cross(a,possible_sizes[i]);
    } 

    // FINAL DECISION BRUTE FORCE ALGORITHM
    bool passed = false;
    int ix = 0; // index of my_pairs
    while(ix < my_pairs.size()){
        //same size
        if(database[my_pairs[ix].first].size() > 0 && database[my_pairs[ix].second].size() > 0){
            bool is_nonoverlap = false;
            for(set<vector<vector<int>>>::iterator it = database[my_pairs[ix].first].begin(); it != database[my_pairs[ix].first].end(); it++){
                for(set<vector<vector<int>>>::iterator jt = database[my_pairs[ix].second].begin(); jt != database[my_pairs[ix].second].end(); jt++){
                    is_nonoverlap = not_overlapping(*it, *jt);
                    if(is_nonoverlap){
                        // the final number is not the product of cross sizes..rather
                        // product of the number of the squares that they contain 2 x cross_size - 1
                        cout << (2 * my_pairs[ix].first - 1) * (2 * my_pairs[ix].second - 1) << endl;
                        return 0;
                    }
                }
            }
        }
        ix++;
    }
    cout << 0 << endl;
    return 0;
}

