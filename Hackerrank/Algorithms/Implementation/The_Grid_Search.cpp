// Name: The_Grid_Search
// WWWW: https://www.hackerrank.com/challenges/the-grid-search
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

vector<vector<int>> create_subarray(vector<vector<int>> &a, int r, int c, int height, int length){

    vector<vector<int>> output(height,vector<int>(length,0));
    for(int i = 0; i < height; i++){
        for(int j = 0; j < length; j++){
            output[i][j] = a[r+i][c+j];
        }
    }
    return output;
}

bool are_equal(vector<vector<int>> &a, vector<vector<int>> &b){
    //check sizes
    if(a.size() != b.size() || a[0].size() != b[0].size()){
        return false;
    }

    //check elements
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}
vector<vector<int>> A= {{1,2,4},{4,5,2},{1,1,9}};

void print_me(vector<vector<int>> &a){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> string_to_int(vector<string> &a){
    vector<vector<int>> output(a.size(),vector<int>(a[0].size(),0));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            output[i][j] = int(a[i][j]) - 48;
        }
    }
    return output;
}

int main() {

//    print_me(A);
//    vector<vector<int>> B = create_subarray(A,1,0,2,2);
//    print_me(B);
//    cout << are_equal(A,A);
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++){
            cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++){
            cin >> P[P_i];
        }
        /* my code - bruteforce */
        // convert to int array
        vector<vector<int>> G_new = string_to_int(G);
        vector<vector<int>> P_new = string_to_int(P);

        //helper variables
        int G_height = G_new.size();
        int G_length = G_new[0].size();

        int P_height = P_new.size();
        int P_length = P_new[0].size();

        // main algo
        bool was_found = false;
        for(int r = 0; r <= G_height - P_height; r++){
            for(int c = 0; c <= G_length - P_length; c++){
                //to increase the speed, check if [0][0] element agrees
                if(G_new[r][c] != P_new[0][0] || G_new[r+1][c+1] != P_new[1][1] ){
                    continue;
                }
                vector<vector<int>> temp = create_subarray(G_new,r,c,P_height,P_length);
                if(are_equal(temp,P_new)){
                    was_found = true;
                    goto jump;
                }
            }
        }
        jump:;
        cout << (was_found ? "YES" : "NO") << endl;
    }
}
